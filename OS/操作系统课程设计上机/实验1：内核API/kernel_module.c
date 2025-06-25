#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/rcupdate.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/sched/signal.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");

MODULE_AUTHOR("FuShengyuan");

MODULE_DESCRIPTION("A simple kernel module with a list and two threads.");

static struct list_head my_list;
static struct task_struct *thread1, *thread2;

spinlock_t lock;

// 定义链表节点结构
struct pid_node
{
    int pid;
    char comm[16];
    struct list_head list;
};

// thread1 函数体
static int thread1_func(void *data)
{

//TODO: add code here
    struct task_struct *p;
    spin_lock(&lock);//开始使用链表，加锁防止其他线程使用
    for_each_process(p) {
        struct pid_node *node = kmalloc(sizeof(struct pid_node), GFP_KERNEL);//新建节点
        if (!node) {//分配失败的处理
            printk(KERN_ERR "Failed to allocate memory for pid_node\n");
            continue;
        }
        node->pid = p->pid;//复制pid
        strncpy(node->comm, p->comm, sizeof(node->comm) - 1);//复制进程名称
        node->comm[sizeof(node->comm) - 1] = '\0'; // 确保字符串终止
        INIT_LIST_HEAD(&node->list);//初始化节点链表指针
        list_add_tail(&node->list, &my_list);//添加节点到表尾
    }
    spin_unlock(&lock);//使用完毕，解锁

    // 等待停止信号
    while (!kthread_should_stop()) {
        msleep_interruptible(1000);//休眠1秒
    }
    return 0;
}
// thread2 函数体
static int thread2_func(void *data)
{

//TODO: add code here
    //循环获取链表的第一个节点
    while (!kthread_should_stop()) {//等待停止信号
        spin_lock(&lock);//开始使用链表，加锁防止其他线程使用
        if (!list_empty(&my_list)) {//判空
            struct pid_node *node = list_first_entry(&my_list, struct pid_node, list);//得到第一个节点
            list_del(&node->list);//删除
            spin_unlock(&lock);//使用完毕，解锁
            printk(KERN_INFO "pid :%d name:%s\n", node->pid, node->comm);
            kfree(node);//释放内存
        } else {
            spin_unlock(&lock);//不使用了也要解锁
            msleep_interruptible(100); //休眠0.1秒，避免忙等待
        }
    }
    return 0;
}

// 模块初始化函数
int kernel_module_init(void)
{
    printk(KERN_INFO "List and thread module init\n");

//TODO: add code here
    INIT_LIST_HEAD(&my_list);//初始化链表
    spin_lock_init(&lock);//初始化锁

    // 创建并启动线程1
    thread1 = kthread_create(thread1_func, NULL, "thread1");
    if (IS_ERR(thread1)) {//异常处理
        printk(KERN_ERR "Failed to create thread1\n");
        return PTR_ERR(thread1);
    }
    wake_up_process(thread1);//唤醒线程1

    // 创建并启动线程2
    thread2 = kthread_create(thread2_func, NULL, "thread2");
    if (IS_ERR(thread2)) {//异常处理
        printk(KERN_ERR "Failed to create thread2\n");
        kthread_stop(thread1);
        return PTR_ERR(thread2);
    }
    wake_up_process(thread2);//唤醒线程2

    return 0;
}

// 模块清理函数
void kernel_module_exit(void)
{
   //TODO: add code here
    // 停止线程1
    if (thread1) {
        kthread_stop(thread1);
    }
    // 停止线程2
    if (thread2) {
        kthread_stop(thread2);
    }
    // 清理链表
    struct pid_node *node, *tmp;
    spin_lock(&lock);//加锁，防止意外访问导致错误
    list_for_each_entry_safe(node, tmp, &my_list, list) {//遍历并删除所有节点
        list_del(&node->list);
        kfree(node);
    }
    spin_unlock(&lock);//解锁
    
    //打印消息
    printk(KERN_INFO "List and thread module exit\n");
}

module_init(kernel_module_init);

module_exit(kernel_module_exit);

