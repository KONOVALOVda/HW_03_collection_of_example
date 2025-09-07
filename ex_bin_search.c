#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sort.h>
#include <linux/bsearch.h>

#define NR_VAL 16
static int arr[NR_VAL];

static int cmp_int(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

static int __init ex_bin_search_init(void)
{
	int i, key = 7, *found;

	pr_info("ex_bin_search: init\n");

	for (i = 0; i < NR_VAL; i++)
		arr[i] = NR_VAL - i;

	sort(arr, NR_VAL, sizeof(int), cmp_int, NULL);

	for (i = 0; i < NR_VAL; i++)
		pr_info("ex_bin_search: arr[%d]=%d\n", i, arr[i]);

	found = bsearch(&key, arr, NR_VAL, sizeof(int), cmp_int);
	if (found)
		pr_info("ex_bin_search: found %d at index %ld\n",
			key, found - arr);
	else
		pr_info("ex_bin_search: %d not found\n", key);

	return 0;
}

static void __exit ex_bin_search_exit(void)
{
	pr_info("ex_bin_search: exit\n");
}

module_init(ex_bin_search_init);
module_exit(ex_bin_search_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KGD");
MODULE_DESCRIPTION("Example: binary search usage");
