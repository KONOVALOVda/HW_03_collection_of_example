#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rbtree.h>
#include <linux/slab.h>

struct my_node {
	int key;
	struct rb_node node;
};

static struct rb_root mytree = RB_ROOT;

static void insert_node(struct my_node *new)
{
	struct rb_node **link = &mytree.rb_node, *parent = NULL;
	struct my_node *this;

	while (*link) {
		parent = *link;
		this = rb_entry(parent, struct my_node, node);

		if (new->key < this->key)
			link = &(*link)->rb_left;
		else if (new->key > this->key)
			link = &(*link)->rb_right;
		else
			return;
	}

	rb_link_node(&new->node, parent, link);
	rb_insert_color(&new->node, &mytree);
	pr_info("ex_rb_tree: inserted %d\n", new->key);
}

static int __init ex_rb_tree_init(void)
{
	int i;
	struct my_node *n;

	pr_info("ex_rb_tree: init\n");

	for (i = 0; i < 5; i++) {
		n = kmalloc(sizeof(*n), GFP_KERNEL);
		n->key = i * 10;
		insert_node(n);
	}

	return 0;
}

static void __exit ex_rb_tree_exit(void)
{
	struct rb_node *node;
	struct my_node *data;

	for (node = rb_first(&mytree); node; node = rb_next(node)) {
		data = rb_entry(node, struct my_node, node);
		pr_info("ex_rb_tree: key=%d\n", data->key);
		kfree(data);
	}
	pr_info("ex_rb_tree: exit\n");
}

module_init(ex_rb_tree_init);
module_exit(ex_rb_tree_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KGD");
MODULE_DESCRIPTION("Example: red-black tree usage");
