//Example: process3.c
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main( ){
    pid_t child_pid;
    // Create a new child process;
    child_pid = fork();
    if (child_pid < 0) {
        printf("forkfailed");
        return 1;
    }
    else if (child_pid == 0) {
        printf ("child process successfullycreated!\n");
        printf ("child_PID = %d,parent_PID = %d\n",getpid(), getppid());
    }
    else {
    wait(NULL);
    printf ("parent process success.created!\n");
    printf ("child_PID = %d, parent_PID = %d\n", getpid() , getppid());
    }
    return 0;
}