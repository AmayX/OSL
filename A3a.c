//Program to send a message from parent process to child process usingmpipe()
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
int fd[2],n, status;
char buffer[100];
pid_t p;
pipe(fd); 
p=fork();
if(p>0) 
{
printf("Parent Passing value to child\n");
write(fd[1],"This is Amay\n",13); 
wait(&status);
}
else 
{
printf("Child printing received value\n");
n=read(fd[0],buffer,100); 
write(1,buffer,n);
}
}