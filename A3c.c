//Program to write and read two messages through the pipe using the parent and the child processes.

#include<stdio.h>
#include<unistd.h>
int main() {
int piperw[2];
int returnstatus;
int pid;
char w[2][40]={"Hi", "This is Amay"};
char r[40];
returnstatus = pipe(piperw);
if (returnstatus == -1) {
printf("Unable to create pipe\n");
return 1;
}
pid = fork();
if (pid == 0) {
read(piperw[0], r,sizeof(r));
printf("Child Process - Reading from pipe – Message 1 is %s\n", r);
read(piperw[0], r,sizeof(r));
printf("Child Process - Reading from pipe –Message 2 is %s\n", r);
} 
else if (pid<0){
    printf("Failed to create child process\n");
}
else { 
printf("Parent Process - Writing to pipe - Message 1 is %s\n", w[0]);
write(piperw[1], w[0], sizeof(w[0]));
printf("Parent Process - Writing to pipe - Message 2 is %s\n", w[1]);
write(piperw[1], w[1], sizeof(w[1]));
}
return 0;
}