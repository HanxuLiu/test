#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{  
    pid_t child;
    child = fork();
    if(child == 0) // child process
    {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        printf("child to call execl, run ls command\n");
        execl("/usr/bin/ls", "ls", NULL); // run ls and send signal
    } else { // parent process
        wait(NULL); // wait for child process signal
        ptrace(PTRACE_CONT, child, NULL, NULL); // tell child to continue
        printf("after child continue, parent exit\n");
    }
    return 0;
}
