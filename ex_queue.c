#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kfifo.h>

#define FIFO_SIZE 16
static DECLARE_KFIFO(my_fifo, int, FIFO_SIZE);

static int __init ex_queue_init(void)
{
	int i, val;

	pr_info("ex_queue: init\n");

	for (i = 0; i < 8; i++) {
		kfifo_in(&my_fifo, &i, 1);
		pr_info("ex_queue: pushed %d\n", i);
	}

	while (!kfifo_is_empty(&my_fifo)) {
		kfifo_out(&my_fifo, &val, 1);
		pr_info("ex_queue: popped %d\n", val);
	}

	return 0;
}

static void __exit ex_queue_exit(void)
{
	pr_info("ex_queue: exit\n");
}

module_init(ex_queue_init);
module_exit(ex_queue_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KGD");
MODULE_DESCRIPTION("Example: queue using kfifo");
