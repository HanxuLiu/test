/*================================================================
*  Author: LiuHanxu
*  Date: 2023-01-06
*  Description: FIXME: I don't known why it can not work
*  with hello.c coding by C, and not understanding result with
*  hello.s coding by asm.
================================================================*/

#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int val;
  int counter = 0;
  pid_t pid = fork();
  if (pid == 0) { // child process
    execl("./demo-asm/hello", "HelloWorld", NULL);
  } else { // parent process
    ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    while (1) {
      wait(&val);
      if (WIFEXITED(val))
          break;
      counter++;
      ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
    }
    printf("Total Instruction number= %d\n", counter);
  }
  return 0;
}
