/* 内核模块开发必需的头文件 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/workqueue.h>
#include <linux/atomic.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("FuShengyuan");
MODULE_DESCRIPTION("deferred work");

struct work_ctx
{
    struct work_struct work;
    int current_id;
};

struct delayed_work my_work;
struct work_ctx works[10];
struct task_struct *threads[10];

int kthread_handler(void *data)
{
    int id = 315 + (int)(long)data; // 计算唯一ID（315 + 索引）
    printk("kthread : %d\n", id);   // 打印线程ID

    // 保持线程运行，直到收到停止信号
    while (!kthread_should_stop())
    {
        msleep_interruptible(10); // 可中断的10ms休眠
    }
    return 0;
}

void work_queue_handler(struct work_struct *work)
{
    // 通过成员变量work反向获取包含它的work_ctx结构体
    struct work_ctx *ctx = container_of(work, struct work_ctx, work);
    printk("work queue : %d\n", ctx->current_id); // 打印顺序ID
}

void delayed_work_handler(struct work_struct *work)
{
    printk("delayed work!\n"); // 延迟5秒后打印
}

int deferred_work_init(void)
{
    printk(KERN_INFO "deferred work module init\n");
    int i;

    /* 初始化并提交10个工作队列任务 */
    for (i = 0; i < 10; i++)
    {
        works[i].current_id = 315 + i;                 // 设置ID（315~324）
        INIT_WORK(&works[i].work, work_queue_handler); // 绑定任务和处理函数
        schedule_work(&works[i].work);                 // 提交到全局工作队列
    }

    /* 创建并启动10个内核线程 */
    for (i = 0; i < 10; i++)
    {
        // 创建线程，传递索引i作为参数
        threads[i] = kthread_create(kthread_handler, (void *)(long)i, "mythread%d", i);
        if (threads[i])
        {
            wake_up_process(threads[i]); // 唤醒线程使其运行
        }
        else
        {
            printk(KERN_ERR "Failed to create kthread %d\n", i); // 错误处理
        }
    }

    /* 初始化并调度延迟工作（5秒后执行） */
    INIT_DELAYED_WORK(&my_work, delayed_work_handler);       // 绑定延迟处理函数
    schedule_delayed_work(&my_work, msecs_to_jiffies(5000)); // 5000ms转jiffies单位

    return 0; // 初始化成功
}

/* 模块退出函数 */
void deferred_work_exit(void)
{
    int i;

    /* 停止所有内核线程 */
    for (i = 0; i < 10; i++)
    {
        if (threads[i])
        {
            kthread_stop(threads[i]); // 发送停止信号并等待线程退出
        }
    }

    /* 取消未执行的延迟工作 */
    cancel_delayed_work_sync(&my_work); // 确保延迟任务被取消

    printk(KERN_INFO "deferred work module exit\n"); // 退出日志
}

/* 指定模块入口和出口函数 */
module_init(deferred_work_init); // 模块加载时调用deferred_work_init
module_exit(deferred_work_exit); // 模块卸载时调用deferred_work_exit