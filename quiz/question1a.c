#include <stdio.h>
#include <sys/types.h>/* defines types used by sys/stat.h */
#include <sys/stat.h>/* defines S_IREAD & S_IWRITE
*/
       #include <sys/stat.h>
       #include <fcntl.h>//creat
         #include <stdlib.h>//exit

#include <unistd.h>//close


int main( ) {
// declaring int variable fd used to store the created file result
int fd;
// creating a file called first.txt using creat system call back and giving read and write access to it 
fd = creat("first.txt", S_IREAD | S_IWRITE);
if (fd == -1)
// if the file can't be opened
printf("Error in opening datafile.dat\n");
else
{
    // if the file successfully opened
printf("datafile.dat opened for read/write access\n");
printf("datafile.dat is currently empty\n");
}
close(fd);
exit (0);
}