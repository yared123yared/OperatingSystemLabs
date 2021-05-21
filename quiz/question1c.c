#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
 int fd;
 ssize_t nread;
 char buf[100];
 fd=open("file2.txt",O_RDONLY);

  if (fd == -1){
        printf("\n\n\tThere was an error creating the file");
    }

 while(nread=read(fd,buf,sizeof buf),nread>0){
  char *outPtr=buf;
  ssize_t nwritten;
  do{
        nwritten=write(1,outPtr,nread);
        if(nwritten>=0){
          nread-=nwritten;
        }
   }while(nread>0);

   int status= close(fd);
   if(status==-1){
        printf("\n\n\tThere was an error closing the file\n");
   }
}
close(fd);
}