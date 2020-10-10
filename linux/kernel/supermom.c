#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/printk.h>

long (*func_ptr)(pid_t pid, uid_t __user *uid);
EXPORT_SYMBOL(func_ptr);

SYSCALL_DEFINE2(supermom, pid_t, pid, uid_t __user*, uid)
{
	return func_ptr(pid, uid);
}
