#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <string.h>
void main(){
int fd;
char *file = "/home/yared/filest.txt";
const char *buf = "My ship is solid!";
ssize_t nr;
int status;
fd = creat (file, 0644);
if (fd == -1)
printf("\n\n\tThere was an error creating the file");
nr = write (fd, buf, strlen (buf));
if (nr == -1)
printf("\n\n\tThere was an error writing to the file\n");
status = close(fd);
if (status == -1)
printf("\n\n\tThere was an error closing the file\n");
}