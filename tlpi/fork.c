#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t p;
    int status = 0;
    p = fork();

    if(-1 == p) {
        printf("I am the parent. Fork was unsuccessful.\n");
    }
    else if(0 == p) {
        printf("I am the child. My pid is %d. My parent's pid is %d.\n", getpid(), getppid());
        sleep(1);
        exit(10); // WEXITSTATUS interpretes it as unsigned. So if -ve value is returned, wrong exit status code is derived.
    } else {
        printf("I am the parent. My pid is %d. Child pid is %d\n", getpid(), p);
        wait(&status);
        if(WIFEXITED(status) != 0)
            printf("Child process exited with exit code %d.\n", WEXITSTATUS(status)); 
        else
            printf("Child process exited normally.\n");
    }
}
