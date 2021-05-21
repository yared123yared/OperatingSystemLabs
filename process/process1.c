//Example: process1.c
#include <sys/types.h>
#include <stdio.h>
int main() {
    int id,i;
    printf("Start of main \n");
    id=fork();
    if(id>0) {
        wait(NULL);
        /*parent process*/
        printf("Parent is running\n");
    }
    else if(id==0){
            /*child process*/
        printf("\n fork created...\n");

    }
    else {
        /*fork creation failed*/
        printf("\n fork creation failed!\n");
    }
    printf("Printing the numbers from 1 to 5\n");
    for(i=1; i<=5; i++)
        printf("%d ",i);
    printf("\n");

    printf("End of the main function...\n") ;

}