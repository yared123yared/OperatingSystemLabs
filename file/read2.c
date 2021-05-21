#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


void main(){
int fd;
char *file = "/home/yared/filest.txt";
const char *buf;
ssize_t nr;
char ch , file_name[25];
FILE *fp;
printf("Enter name of a file you wish to see\n");
gets(file_name);

int status;
// fd = creat (file, 0644);
fd=fopen(file_name,"r");
if (fd == -1)
printf("\n\n\tThere was an error opening the file");
nr = read (fd, ch, sizeof(ch));
if (nr == -1)
printf("\n\n\tThere was an error reading to the file\n");

