#include<stdio.h>
#include<pthread.h>
//  thread function defination

void* threadFunction(void* args){
    printf("I am a Thread function\n");
}
int main(){
    // creating thread id
    pthread_t id;
    int ret;
    ret=pthread_create(&id,NULL,&threadFunction,NULL);
    if(ret==0){
        printf("Thread created successfully.\n");
    }else{
        printf("Thread not created.\n");
    }
    printf("I am main function");
    return 0;

}