#include<stdio.h>
#include<unistd.h>

char c = 'A';
int main(int argc, char *argv[])
{
    while(1)
    {
        sleep(1);
        printf("%c",c);
	printf("(pid = %d)\n", getpid());
    }
    return 0;
}
