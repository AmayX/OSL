//Two-way Communication Using Pipes
#include<stdio.h>
#include<unistd.h>
int main() {
int pipefds1[2], pipefds2[2];
int returnstatus1, returnstatus2;
int pid;
char w1[40] = "Hi";
char w2[40] = "This is Amay";
char r[40];
returnstatus1 = pipe(pipefds1);
if (returnstatus1 == -1) {
printf("Unable to create pipe 1 \n");
return 1;
}
returnstatus2 = pipe(pipefds2);
if (returnstatus2 == -1) {
printf("Unable to create pipe 2 \n");
return 1;
}
pid = fork();
if (pid != 0) {
close(pipefds1[0]); 
close(pipefds2[1]); 
printf("In Parent: Writing to pipe 1 – Message is %s\n", w1);
write(pipefds1[1], w1, sizeof(w1));
read(pipefds2[0], r, sizeof(r));
printf("In Parent: Reading from pipe 2 – Messageis %s\n", r);
}
else { 
close(pipefds1[1]); 
close(pipefds2[0]);
read(pipefds1[0], r, sizeof(r));
printf("In Child: Reading from pipe 1 – Message is %s\n", r);
printf("In Child: Writing to pipe 2 – Message is %s\n", w2);
write(pipefds2[1], w2, sizeof(w2));
}
return 0;
}
