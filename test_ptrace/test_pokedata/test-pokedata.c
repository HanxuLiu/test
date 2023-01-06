#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c = 'B';  //把输出修改为'B'
    long addr = 0x0000000000404048; // c.out的变量c的偏移地址
    pid_t apid = atoi(argv[1]);
    ptrace(PTRACE_ATTACH, apid, 0, 0); //attach进程号为apid的进程，进行进程内存访问
    wait(NULL);  
    ptrace(PTRACE_POKEDATA, apid, addr, c); //对addr的偏移地址内容修改为c
    ptrace(PTRACE_CONT, apid, 0, 0);
    ptrace(PTRACE_DETACH, apid, NULL, NULL);
    return 0;
}
