#include<stdio.h> 
#include<fcntl.h> 
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    // buffer 
    const char *buf = "This is the First file I created";
    int fd = open("first.txt", O_RDWR);

    // check for an error
    if (fd == -1){
        printf("\n\n\tThere was an error opening  the file");
    }
    ssize_t nr;
    // write 
    nr = write(fd, buf, strlen(buf));

    if(nr == -1 ){
        printf("Error Number % d\n", errno); 

    }
    int file2 = creat("./file2.txt", 0644);
    if (file2 == -1){
        printf("\n\n\tThere was an error creating the file");
    }

    char* c = (char *) calloc(100, sizeof(char));

    // open file in read only
    int file1 = open("./first.txt", O_RDONLY);
    if (file1 == -1){
        printf("\n\n\tThere was an error opening the file");
    }

    // move cursor by 5 space
    off_t ls =  lseek(file1, 5, SEEK_SET);

    int sz  = read(file1, c, 100);
    if (sz == -1){
        printf("\n\n\tThere was an error reading the file");
    }
    // write
    ssize_t file1size = write (file2, c, strlen(c));

    if (file1size == -1){
        printf("\n\n\tThere was an error writing the file");
    }

    printf("%s", c);
    close(file1);
    close(file2);

    exit (0);

}