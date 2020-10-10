This file should contain:

-	Your name & UNI (or those of all group members for group assignments)
-	Homework assignment number
-	Description for each part

The description should indicate whether your solution for the part is working
or not. You may also want to include anything else you would like to
communicate to the grader, such as extra functionality you implemented or how
you tried to fix your non-working code.

part3:
	my solution works
	my test program has two system calls, the first one is good and if run the
	a.out by sudo ./a.out, I get 0 returned from system call, the second one is
	the wrong one by modifying the parent pid.

part4:
	my solution works
	except copying the implementation from part3, I use SYSCALL_SYMBOL in kernel/supermom.c
	to expose the function pointer and use extern in user/supermom.c to implemente the
	functionality and pass the function pointer to kernel. then in the simple_init function
	I assign the implementation of the supermom to the function pointer.