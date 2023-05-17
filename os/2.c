#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

#define PTHREAD_NUM 16

unsigned long sum = 0;

void *thread(void *arg)
{
    for (int i = 0; i < 10000; i++) {
        //sum += 1;
        //解决方案1
        __sync_fetch_and_add(&sum, 1);
    }
}

int main(void) {
    printf("bufore ...sum = %lu\n", sum);

    pthread_t pthread[PTHREAD_NUM];
    int ret;
    void *retval[PTHREAD_NUM];

    for (int i = 0; i < PTHREAD_NUM; ++i) {
        ret = pthread_create(&pthread[i], NULL, thread, NULL);
        if (ret != 0) {
            perror("cause:");
            printf("create pthread %d failed.\n", i + 1);
        }
    }

    for (int i = 0; i < PTHREAD_NUM; i++) {
        pthread_join(pthread[i], &retval[i]);
    }

    printf("after...sum = %lu", sum);
}
