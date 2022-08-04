#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    int fd[2],n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p=fork();
    if(p>0)
   {
         printf("Parent Passing value to child\n");
         write(fd[1],"hello\n",6);      //Send data to child
         wait(NULL);
    }
    else
    {
          printf("Child printing received value\n");
          n=read(fd[0],buffer,100);         //child reading the data
          write(1,buffer,n);
    }
    return 0;
}
