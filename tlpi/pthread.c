#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int retval = 0;

void* 
func(void* arg)
{
    printf("Child thread. Got from parent: %s", (char*) arg);
    retval = 10;
    return (void*)&retval;
}

int main()
{
    pthread_t pt;
    pthread_attr_t pta;
    int status;
    void* ret;

    status = pthread_attr_init(&pta);
    if(0 != status) {
        printf("pthread_attr_init error.\n");
        exit(0);
    }

    status = pthread_create(&pt, &pta, func, "Hello World\n");
    if(0 != status) {
        printf("pthread_create error.\n");
        exit(0);
    }

    printf("This is parent.\n");

    status = pthread_join(pt, &ret);
    if(0 != status) {
        printf("pthread_join error.\n");
        exit(0);
    }

    printf("Parent received %d.\n", *((int*)ret));

    printf("Parent exiting.\n");
}
