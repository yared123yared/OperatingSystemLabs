#include<stdio.h> 
  
#include<unistd.h>  
int main() 
{    
    char s[100]; 
  
    printf("%s\n", getcwd(s, 100)); 
  
    chdir("yared"); 
  
    printf("%s\n", getcwd(s, 100)); 
  
    return 0; 
} 