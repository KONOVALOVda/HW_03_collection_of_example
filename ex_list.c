#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct my_node {
	int val;
	struct list_head list;
};

static LIST_HEAD(my_list);

static int __init ex_list_init(void)
{
	int i;
	struct my_node *node;

	pr_info("ex_list: init\n");

	for (i = 0; i < 5; i++) {
		node = kmalloc(sizeof(*node), GFP_KERNEL);
		node->val = i;
		list_add_tail(&node->list, &my_list);
		pr_info("ex_list: added %d\n", i);
	}

	list_for_each_entry(node, &my_list, list)
		pr_info("ex_list: node=%d\n", node->val);

	return 0;
}

static void __exit ex_list_exit(void)
{
	struct my_node *node, *tmp;

	list_for_each_entry_safe(node, tmp, &my_list, list) {
		pr_info("ex_list: deleting %d\n", node->val);
		list_del(&node->list);
		kfree(node);
	}
	pr_info("ex_list: exit\n");
}

module_init(ex_list_init);
module_exit(ex_list_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KGD");
MODULE_DESCRIPTION("Example: linked list usage");
