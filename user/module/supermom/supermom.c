#include <linux/module.h>
#include <linux/printk.h>

#define MODULE_NAME "Supermom"

int simple_init(void)
{
	printk(KERN_INFO "Loading %s\n", MODULE_NAME);
	return 0;
}

void simple_exit(void)
{
	printk(KERN_INFO "Removing %s\n", MODULE_NAME);
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION(MODULE_NAME);
MODULE_AUTHOR("cs4118");
