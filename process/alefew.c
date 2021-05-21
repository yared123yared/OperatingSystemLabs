//Example: alefew.c
#include <sys/types.h>
#include <stdio.h>

int main(){
    int a=10;
    int b;
    pid_t child_pid;
    b=100;
    printf("before fork\n");
    child_pid=fork();
    if(child_pid==0){
        a++;
        b++;
        printf("hi from child\n");
    }else{
        wait(child_pid);
        printf("After fork , a =%d , b=%d\n",a,b);
        exit(0);
    }
    //  printf("After fork , a =%d , b=%d\n",a,b);

}