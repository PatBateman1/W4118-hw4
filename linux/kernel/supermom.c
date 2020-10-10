#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <unistd.h>
#include <errno.h>


SYSCALL_DEFINE2(supermom, pid_t, pid, uid_t __user*, uid)
{
    pid_t parent;
    uid_t uid;
    uid_t euid;

    /* check pid == ppid */
    parent = task_gtid_vnr(current->real_parent);
    if (pid != parent) {
        printk(KERN_INFO "Not Yo Mama");
        errno = EINVAL;
        return -12;
    }

    /* handle uid and euid */
    uid = from_kuid_munged(current_user_ns(), current_uid());
    euid = from_kuid_munged(current_user_ns(), current_euid());
    if (uid) {
        copy_to_user(uid, &euid, sizeof(uid_t));
    }
    if (euid == 0) {
        return 0;
    } else {
        errno = EACCES;
        return -1;
    }
}   