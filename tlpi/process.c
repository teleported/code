#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int count = 9;  /* Stored in initialised data segment */
int size;       /* Stored in uninitialised data segement */

extern char etext, edata, end;
                /* Provided by CRT, points to the memory area one past end of the segment and begining of next */
                /* &etext is the start of ininised data segement*/

int main()                          /* Allocated in frame for main() */
{
    static int key = 1;             /* Stored in initialised data segment */
    static char c[1024];            /* Stored in uninitialised data segment */
    int i = 0;                      /* Stored in stack frame of main() */

    pid_t pid;                      /* pid_t is integer type defined in SUSv3*/
    pid = getpid();
    printf("My pid is %d\n", pid);

    pid_t ppid;
    ppid = getppid();
    printf("My parent's pid is %d\n", ppid);

    char* p = malloc(10);   /* Pointer to memory in heap segment */
    free(p);

    printf("Start of initialised data segment:   %p\n", &etext);
    printf("Start of uninitialised data segment: %p\n", &edata);
    printf("End of uninitialised data segment:   %p\n", &end);
}
