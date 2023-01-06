#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv)
{  
    pid_t child;
    child = atoi (argv[1]);
    printf("try to attach child: %d\n", child);
    int ret = ptrace(PTRACE_ATTACH, child, NULL, NULL); // attch child process
    if (ret == 0) 
      printf("attach child %d success !\n", child);
    else {
      printf("attach error !\n");
      return 1;
    }
    wait(NULL); // wait for child process signal
    ptrace(PTRACE_KILL, child, NULL, NULL); // kill child to process
    printf("kill child success !\n");
    return 0;
} 
