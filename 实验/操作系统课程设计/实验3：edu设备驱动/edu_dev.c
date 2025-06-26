#include <asm/io.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/delay.h>
#include <linux/pid.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/types.h>

// 保存edu设备信息
struct edu_dev_info
{
	resource_size_t io;
	long range, flags;
	void __iomem *ioaddr;
	int irq;
};

static struct pci_device_id id_table[] = {
	{PCI_DEVICE(0x1234, 0x11e8)}, // edu设备id
	{
		0,
	} // 最后一组是0，表示结束
};

struct edu_dev_info *edu_info;
spinlock_t lock;

/// @brief edu设备发现函数
static int edu_driver_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
	int ret = 0;
	printk("executing edu driver probe function!\n");

	ret = pci_enable_device(dev);
	if (ret)
	{
		printk(KERN_ERR "IO Error.\n");
		return -EIO;
	}

	// 分配edu_dev_info内存
	edu_info = kzalloc(sizeof(struct edu_dev_info), GFP_KERNEL);
	if (!edu_info)
	{
		ret = -ENOMEM;
		goto out_mypci;
	}

	// 请求PCI资源区域
	ret = pci_request_regions(dev, "edu_dirver");
	if (ret)
	{
		printk("PCI request regions err!\n");
		goto out_kfree;
	}

	// 映射BAR0到虚拟地址
	edu_info->ioaddr = pci_ioremap_bar(dev, 0);
	if (!edu_info->ioaddr)
	{
		printk("ioremap failed\n");
		ret = -ENOMEM;
		goto out_regions;
	}

	// 设置驱动私有数据
	pci_set_drvdata(dev, edu_info);
	printk("Probe succeeds.PCIE ioport addr start at %llX, edu_info->ioaddr is 0x%p.\n",
		   (unsigned long long)pci_resource_start(dev, 0), edu_info->ioaddr);

	return 0;

out_regions:
	pci_release_regions(dev);
out_kfree:
	kfree(edu_info);
out_mypci:
	pci_disable_device(dev);
	return ret;
}

/// @brief edu设备移除函数
static void edu_driver_remove(struct pci_dev *dev)
{
	struct edu_dev_info *info = pci_get_drvdata(dev); // 获取私有数据

	iounmap(info->ioaddr);	  // 取消地址映射
	pci_release_regions(dev); // 释放PCI资源
	kfree(info);			  // 释放edu_dev_info内存
	pci_disable_device(dev);  // 关闭PCI设备
	printk("Device is removed successfully.\n");
}

MODULE_DEVICE_TABLE(pci, id_table);

static struct pci_driver pci_driver = {
	.name = "edu_dirver",
	.id_table = id_table,
	.probe = edu_driver_probe,
	.remove = edu_driver_remove,
};

#define EDU_DEV_MAJOR 200
#define EDU_DEV_NAME "edu"

int current_id = 0;

struct user_data
{
	int id;
	atomic64_t data; // 原子变量存储结果
};

struct thread_data
{
	struct user_data *user_data_ptr;
	int input_data;
};

int kthread_handler(void *data)
{
	struct thread_data *thread_data = (struct thread_data *)data;
	uint64_t result = 1;
	int i;

	// 计算阶乘（假设设备计算需通过IO操作，此处模拟计算）
	for (i = 1; i <= thread_data->input_data; i++)
		result *= i;

	// 原子写入结果
	atomic64_set(&thread_data->user_data_ptr->data, result);
	printk("Factorial of %d is %llu\n", thread_data->input_data, result);

	kfree(thread_data); // 释放线程数据
	return 0;
}

/// @brief open处理函数
static int edu_dev_open(struct inode *inode, struct file *filp)
{
	struct user_data *user_data = kmalloc(sizeof(struct user_data), GFP_KERNEL);
	if (!user_data)
		return -ENOMEM;

	user_data->id = current_id++;
	filp->private_data = user_data; // 绑定到filp
	return 0;
}

/// @brief close处理函数
static int edu_dev_release(struct inode *inode, struct file *filp)
{
	struct user_data *user_data = filp->private_data;
	kfree(user_data); // 释放用户数据内存
	return 0;
}

/// @brief ioctl处理函数
long edu_dev_unlocked_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct user_data *user_data = filp->private_data;
	struct thread_data *thread_data;

	switch (cmd)
	{
	case 0: // 写入计算值
		thread_data = kmalloc(sizeof(struct thread_data), GFP_KERNEL);
		if (!thread_data)
			return -ENOMEM;

		thread_data->user_data_ptr = user_data;
		thread_data->input_data = (int)arg;

		// 创建并启动内核线程
		struct task_struct *task = kthread_create(kthread_handler, thread_data, "edu_kthread");
		if (IS_ERR(task))
		{
			kfree(thread_data);
			return PTR_ERR(task);
		}
		wake_up_process(task);
		break;

	case 1: // 读取结果
		return atomic64_read(&user_data->data);

	default:
		return -EINVAL;
	}
	return 0;
}

static struct file_operations edu_dev_fops = {
	.open = edu_dev_open,
	.release = edu_dev_release,
	.unlocked_ioctl = edu_dev_unlocked_ioctl,
};

/// @brief 驱动初始化
static int __init edu_dirver_init(void)
{
	printk("HELLO PCI\n");
	int ret = register_chrdev(EDU_DEV_MAJOR, EDU_DEV_NAME, &edu_dev_fops);
	if (ret < 0)
	{
		printk("Register chrdev failed\n");
		return ret;
	}

	ret = pci_register_driver(&pci_driver);
	if (ret)
	{
		unregister_chrdev(EDU_DEV_MAJOR, EDU_DEV_NAME);
		printk("PCI register failed\n");
		return ret;
	}

	spin_lock_init(&lock);
	printk("Driver initialized\n");
	return 0;
}

/// @brief 驱动注销
static void __exit edu_dirver_exit(void)
{
	unregister_chrdev(EDU_DEV_MAJOR, EDU_DEV_NAME);
	pci_unregister_driver(&pci_driver);
	printk("GOODBYE PCI\n");
}

MODULE_LICENSE("GPL");
module_init(edu_dirver_init);
module_exit(edu_dirver_exit);