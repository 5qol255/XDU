// 内核模块必需的头文件
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/mutex.h>
#include <linux/delay.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

// 共享数据结构（volatile确保内存可见性）
static struct
{
    struct mutex lock;          // 保护共享数据的互斥锁
    volatile int counter;       // 共享计数器
    volatile bool stop_threads; // 线程停止标志
} shared_data;

// 线程参数结构体（用于传递线程ID）
struct thread_param
{
    int id; // 线程标识符
};

// 定义两个内核线程指针
static struct task_struct *thread1;
static struct task_struct *thread2;

static int worker(void *data)
{
    struct thread_param *param = (struct thread_param *)data;
    int local_count; // 用于临时存储计数器值

    // 主循环：检查停止条件
    while (!kthread_should_stop() && !shared_data.stop_threads)
    {
        mutex_lock(&shared_data.lock);     // 获取互斥锁
        shared_data.counter++;             // 安全修改共享计数器
        local_count = shared_data.counter; // 获取当前计数器值
        // 在临界区内打印保证输出的原子性
        pr_info("Thread %d: counter = %d\n", param->id, local_count);
        mutex_unlock(&shared_data.lock); // 释放互斥锁

        msleep(1000); // 主动让出CPU1秒（模拟工作负载）
    }

    kfree(param); // 释放动态分配的线程参数内存
    return 0;     // 符合内核线程函数规范
}

static int __init mutex_demo_init(void)
{
    struct thread_param *param1, *param2; // 线程参数指针

    // 初始化共享数据结构
    mutex_init(&shared_data.lock);    // 初始化互斥锁
    shared_data.counter = 0;          // 计数器归零
    shared_data.stop_threads = false; // 初始化停止标志

    // 动态分配线程参数（内核空间内存）
    param1 = kmalloc(sizeof(struct thread_param), GFP_KERNEL); // 分配参数1
    param2 = kmalloc(sizeof(struct thread_param), GFP_KERNEL); // 分配参数2
    // 错误处理：任一分配失败时清理内存
    if (!param1 || !param2)
    {
        kfree(param1); // 安全释放可能分配成功的内存
        kfree(param2);
        return -ENOMEM; // 返回内存不足错误码
    }
    param1->id = 1; // 设置第一个线程ID
    param2->id = 2; // 设置第二个线程ID

    // 创建并启动第一个内核线程
    thread1 = kthread_run(worker, param1, "mutex_demo_thread1");
    // 错误处理：线程创建失败
    if (IS_ERR(thread1))
    {
        kfree(param1); // 释放参数内存
        kfree(param2);
        return PTR_ERR(thread1); // 返回错误码
    }

    // 创建并启动第二个内核线程
    thread2 = kthread_run(worker, param2, "mutex_demo_thread2");
    // 错误处理：第二个线程失败时停止第一个线程
    if (IS_ERR(thread2))
    {
        kthread_stop(thread1); // 终止已创建的线程1
        kfree(param1);         // 清理参数内存
        kfree(param2);
        return PTR_ERR(thread2);
    }

    pr_info("Mutex demo module loaded\n"); // 加载成功日志
    return 0;                              // 返回成功状态
}

static void __exit mutex_demo_exit(void)
{
    shared_data.stop_threads = true; // 设置全局停止标
    if (thread1 && !IS_ERR(thread1))
        kthread_stop(thread1); // 等待线程退出
    if (thread2 && !IS_ERR(thread2))
        kthread_stop(thread2);

    mutex_destroy(&shared_data.lock);        // 销毁互斥锁
    pr_info("Mutex demo module unloaded\n"); // 卸载日志
}

// 注册模块入口/出口函数
module_init(mutex_demo_init); // 指定初始化函数
module_exit(mutex_demo_exit); // 指定清理函数