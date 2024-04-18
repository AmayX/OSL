#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = getpid();
    int wstatus;

    printf("Current Process PID: %d\n", pid);
    printf("Creating child process...\n");
    pid_t child = fork();
    
    if (child == 0) { //Executed by child process
        printf("Child process PID: %d, Parent process PID: %d\n", getpid(), getppid());
        
        // Replace the child process with a new process using exec
        execl("/bin/ls", "ls", "-a", NULL);
        
        // If exec fails, the code below this line will not be executed
        printf("Exec failed\n");
    }
    else if (child < 0) {
        printf("Fork failed\n");
    }
    else {
        printf("Parent process PID: %d\n", getpid()); //Executed by parent process
        wait(&wstatus);
    }

    return 0;
}
