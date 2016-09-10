#include <unistd.h>
#include <stdio.h>

int main()
{
    char* argv[2];
    char* envp[1];

    argv[0] = "date";
    argv[1] = NULL;
    envp[0] = NULL;

    if(-1 == execve("/usr/bin/date", argv, envp))
        printf("execve() failed.\n");
    printf("We should not be here.\n");
}
