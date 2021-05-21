//Example: process0.c
#include <sys/types.h>
#include <stdio.h>
int main(){
    int id;
    printf("demo on process creation\n");
    id=fork();
    if(id > 0) {
    /*parent process*/
    // wait(NULL);
    printf("This is parent process [process id:%d].\n",getpid());
    // printf("This is parent of parent process [process id:%d].\n",getppid());
    }

    else if (id==0) {
    /* child process*/
    // printf("fork child process[process id:%d].\n",getpid());
    // printf("fork parent process id:%d].\n",getppid());
    printf ("child_PID = %d,parent_PID = %d\n",getpid(), getppid());
    }
    else {
    /*for creation failed!*/
    printf("fork creationfailed\n");
}
printf("excution finished\n");
return 0;
}
