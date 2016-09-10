// Parent and forked child share the same file descriptor
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    FILE* fd = fopen("message.txt", "w");

    int p = fork();
    
    if(p == -1) {
        printf("fork() error.\n");
        fclose(fd);
    } else if (p == 0) {
        fwrite("From child\n", 1, 11, fd);
        exit(0);
    } else {
        int status;
        wait(&status);
        fwrite("From parent\n", 1, 12, fd);
        fclose(fd);
        exit(0);
    }

}
