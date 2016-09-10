#include <unistd.h>
#include <stdio.h>
#include <string.h>

extern char** environ;

int main(int argc, char* argv[])
{
    int i = 0;
    for(i = 0; i < argc; ++i)
        printf("argv[%d] = %s\n", i, argv[i]);

    printf("Reading my script %s\n", argv[argc-1]);
    FILE* fd = fopen(argv[argc-1], "r");
    char buff[10];
    while(!feof(fd)) {
        memset(buff, 0, 10);
        fread(buff, 1, 10, fd);
        fwrite(buff, 1, 10, stdout);
    }
    fclose(fd);
}
