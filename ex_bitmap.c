#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/bitmap.h>

#define BITMAP_SIZE 32
static DECLARE_BITMAP(my_bitmap, BITMAP_SIZE);

static int __init ex_bitmap_init(void)
{
	int i;

	pr_info("ex_bitmap: init\n");

	bitmap_zero(my_bitmap, BITMAP_SIZE);
	bitmap_set(my_bitmap, 3, 1);
	bitmap_set(my_bitmap, 7, 1);

	for (i = 0; i < BITMAP_SIZE; i++)
		if (test_bit(i, my_bitmap))
			pr_info("ex_bitmap: bit %d is set\n", i);

	return 0;
}

static void __exit ex_bitmap_exit(void)
{
	pr_info("ex_bitmap: exit\n");
}

module_init(ex_bitmap_init);
module_exit(ex_bitmap_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KGD");
MODULE_DESCRIPTION("Example: bitmap usage");
