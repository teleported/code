// Statically initializing mutex
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int resource = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* producer(void* arg)
{
    while(1) {
        sleep(1);
        pthread_mutex_lock(&mtx);
        resource += 1;
        printf("Produced an item. Resources available: %d\n", resource);
        pthread_mutex_unlock(&mtx);
        pthread_cond_signal(&cond);
        sleep(1);
    }
    return NULL;
}


void* consumer(void* arg)
{
    while(1) {
        sleep(2);
        pthread_mutex_lock(&mtx);
        while(resource == 0) {
            pthread_cond_wait(&cond, &mtx);
        }
        resource -= 1;
        printf("Consumed one item. Resources available: %d\n", resource);
        pthread_mutex_unlock(&mtx);
        sleep(2);
    }
}

int main()
{
    pthread_t pt1;
    pthread_t pt2;
    int status;

    status = pthread_create(&pt1, NULL, producer, NULL);
    if(0 != status) {
        printf("pthread_create error for pt1.\n");
        exit(0);
    }

    status = pthread_create(&pt2, NULL, consumer, NULL);
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


}
