/*
Like fork(), vfork() is used by the calling process to create a new child process. 
However, vfork() is expressly designed to be used in programs where the child performs an immediate exec() call.
    - Page tables are shared between child and parent until child does exec (file descriptors are duplicated)
    - Execution of parent process is suspended until child has called exec() or exit() (child is guaranteed to run before parent in this case)
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t p;
    int flag = 0; /* Changes made by child can be seen by parent, till child does exec() */
    int status = 0;
    p = vfork();

    if(-1 == p) {
        printf("I am the parent. Fork was unsuccessful.\n");
    }
    else if(0 == p) {
        flag++;
        printf("I am the child. My pid is %d. My parent's pid is %d. flag is %d.\n", getpid(), getppid(), flag);
        sleep(1);
        exit(10); // WEXITSTATUS interpretes it as unsigned. So if -ve value is returned, wrong exit status code is derived.
    } else {
        flag++;
        printf("I am the parent. My pid is %d. Child pid is %d. flag is %d.\n", getpid(), p, flag);
        wait(&status);
        if(WIFEXITED(status) != 0)
            printf("Child process exited with exit code %d.\n", WEXITSTATUS(status)); 
        else
            printf("Child process exited normally.\n");
    }
}
