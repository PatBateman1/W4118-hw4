#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/printk.h>

SYSCALL_DEFINE2(supermom, pid_t, pid, uid_t __user*, uid)
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
