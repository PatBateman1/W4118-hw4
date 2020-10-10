#include <linux/module.h>
#include <linux/printk.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

#define MODULE_NAME "Supermom"

extern long (*func_ptr)(pid_t pid, uid_t __user *uid);

long helper(pid_t pid, uid_t __user *uid)
{
	pid_t parent;
	uid_t euid;

	/* check pid == ppid */
	parent = task_tgid_vnr(current->real_parent);
	if (pid != parent) {
		pr_info("Not Yo Mama\n");
		return -EINVAL;
	}

	/* handle uid and euid */
	euid = from_kuid_munged(current_user_ns(), current_euid());
	if (uid)
		if (copy_to_user(uid, &euid, sizeof(uid_t)))
			return -EFAULT;

	if (euid == 0)
		return 0;
	else
		return -EACCES;
}

int simple_init(void)
{
	printk(KERN_INFO "Loading %s\n", MODULE_NAME);
	func_ptr = helper;
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
