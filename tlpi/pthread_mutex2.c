// Dynamically initializing mutex
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int counter = 0;
static pthread_mutex_t mtx;

void* func(void* arg)
{
    int loop = *((int*)arg);
    int i = 0;
    int s = 0;
    int val = 0;

    for(i = 0; i < loop; ++i) {
        s = pthread_mutex_lock(&mtx);
        if(s != 0) {
            printf("pthread_mutex_lock error.\n");
            exit(0);
        }
        val = counter;
        val++;
        counter = val;
        s = pthread_mutex_unlock(&mtx);
        if(s != 0) {
            printf("pthread_mutex_unlock error.\n");
            exit(0);
        }

    }

    return NULL;
}

int main()
{
    pthread_t pt1;
    pthread_t pt2;
    pthread_mutexattr_t mattr;
    int loops = 1000000;
    int status;

    status = pthread_mutexattr_init(&mattr);
    if(0 != status) {
        printf("pthread_mutexattr_init error.\n");
        exit(0);
    }


    status = pthread_mutex_init(&mtx, &mattr);
    if(0 != status) {
        printf("pthread_mutex_init error.\n");
        exit(0);
    }

    status = pthread_create(&pt1, NULL, func, &loops);
    if(0 != status) {
        printf("pthread_create error for pt1.\n");
        exit(0);
    }

    status = pthread_create(&pt2, NULL, func, &loops);
    if(0 != status) {
        printf("pthread_create error for pt2.\n");
        exit(0);
    }

    status = pthread_join(pt1, NULL);
    if(0 != status) {
        printf("pthread_join error for pt1.\n");
        exit(0);
    }

    status = pthread_join(pt2, NULL);
    if(0 != status) {
        printf("pthread_join error for pt2.\n");
        exit(0);
    }

    status = pthread_mutex_destroy(&mtx);
    if(0 != status) {
        printf("pthread_mutex_destroy error.\n");
        exit(0);
    }

    status = pthread_mutexattr_destroy(&mattr);
    if(0 != status) {
        printf("pthread_mutexattr_destroy error.\n");
        exit(0);
    }


    printf("Global variable value is %d.\n", counter);

}
