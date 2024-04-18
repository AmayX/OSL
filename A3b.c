//Program to write and read two messages using pipe.
#include<stdio.h>
#include<unistd.h>
int main() {
int piperw[2];
int returnstatus;
char w[2][40]={"Hi", "This is Amay"};
char r[40];
returnstatus = pipe(piperw);
if (returnstatus == -1) {
printf("Unable to create pipe\n");
return 1;
}

printf("Writing to pipe - Message 1 is %s\n",w[0]);
write(piperw[1], w[0],sizeof(w[0]));
read(piperw[0], r, sizeof(r));
printf("Reading from pipe – Message 1 is %s\n",r);
printf("Writing to pipe - Message 2 is %s\n",w[0]);
write(piperw[1], w[1],sizeof(w[1]));
read(piperw[0], r, sizeof(r));
printf("Reading from pipe – Message 2 is %s\n",r);
return 0;
}