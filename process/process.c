//Example: process.c
#include <sys/types.h>
#include <stdio.h>
int a = 10;
int main(void)
{
    int b;
    int pid;/*process id */
    b = 100;
    printf("before fork\n");
    pid = fork();
    if(pid == 0){ /* child */
        a++; b++;
    }
    else /* parent */
        //  wait(NULL);
         a--; b--;
    printf("after fork, a = %d, b = %d\n",a, b);
 exit(0);
}