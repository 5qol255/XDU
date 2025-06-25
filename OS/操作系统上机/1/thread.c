#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>

static int count = 0;
static int turn = 0; // 控制线程交替的变量
static struct task_struct *thread0, *thread1;

// 线程函数
int thread_func(void *arg)
{
    int self_id = (long)arg;
    int other_id = 1 - self_id;

    while (!kthread_should_stop())
    {
        // 等待自己的回合
        while (turn != self_id)
        {
            if (kthread_should_stop() || count >= 10)
            {
                goto exit;
            }
            schedule(); // 让出CPU，避免忙等
        }
        // 检查是否已完成所有操作
        if (count >= 10)
            break;
        // 临界区：操作共享变量
        count++;
        printk(KERN_INFO "Thread %d: count = %d\n", self_id, count);
        // 交还给对方线程
        turn = other_id;
        // 再次检查条件
        if (count >= 10)
            break;
    }

exit:
    return 0;
}

// 模块初始化
static int __init my_module_init(void)
{
    // 创建内核线程
    thread0 = kthread_create(thread_func, (void *)0L, "thread0");
    if (IS_ERR(thread0))
    {
        printk(KERN_ERR "Failed to create thread0\n");
        return PTR_ERR(thread0);
    }
    thread1 = kthread_create(thread_func, (void *)1L, "thread1");
    if (IS_ERR(thread1))
    {
        kthread_stop(thread0);
        printk(KERN_ERR "Failed to create thread1\n");
        return PTR_ERR(thread1);
    }

    // 启动线程
    wake_up_process(thread0);
    wake_up_process(thread1);

    printk(KERN_INFO "Module loaded\n");
    return 0;
}

// 模块退出
static void __exit my_module_exit(void)
{
    kthread_stop(thread0);
    kthread_stop(thread1);
    printk(KERN_INFO "Module unloaded. Final count: %d\n", count);
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");