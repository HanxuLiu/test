#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#ifdef __x86_64__
#include <sys/reg.h>
#include <sys/user.h>
#endif
#include <errno.h>
#include <stdarg.h>
#include <stdlib.h>
#include <signal.h>
#include <syscall.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
	printf("Expected a program name as argument\n");
	return -1;
    }
    pid_t child_pid = fork();
    if (child_pid == 0) {
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	execl(argv[1], argv[1], 0);
    } else if (child_pid > 0) {
	int wait_status;
	unsigned counter = 0;
	/* Wait for child to stop on its first instruction */
	wait(&wait_status);
	while (WIFSTOPPED(wait_status)) {
	    counter++;
#ifdef __x86_64__
	    struct user_regs_struct regs;
	    ptrace(PTRACE_GETREGS, child_pid, 0, &regs);
	    unsigned insn = ptrace(PTRACE_PEEKTEXT, child_pid, regs.rip, 0);
	    long pc = regs.rip;
#elif defined(__other_arch__)
	    long pc = ptrace(PTRACE_PEEKUSER, child_pid, 64, 0);
	    unsigned insn = ptrace(PTRACE_PEEKTEXT, child_pid, pc, 0);
#endif
	    printf("counter = %d, pc = 0x%08x, insn = 0x%08x\n", counter, pc, insn);
	    /* Make the child execute another instruction */
	    ptrace(PTRACE_SINGLESTEP, child_pid, 0, 0);
	    /* Wait for child to stop on its next instruction */
	    wait(&wait_status);
	}
	printf("the child executed %u instructions\n", counter);
    }
    return 0;
}
