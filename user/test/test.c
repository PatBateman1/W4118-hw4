#include <stdio.h>
#include <unistd.h>
#include <errno.h>

/*
 * testing program for part3
 */
int main(void)
{
	pid_t pid;
	pid_t ppid;
	uid_t uid;

	pid = getpid();
	ppid = getppid();
	uid = getuid();
	printf("pid is: %d, ppid is :%d\n", pid, ppid);

	long res;

	res = syscall(400, ppid, &uid);
	printf("success: %d\n", res);
	printf("errno: %d\n", errno);

	res = syscall(400, ppid + 143, &uid);
	printf("fail: %d\n", res);
	printf("errno: %d\n", errno);

	return 0;
}
