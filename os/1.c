#include<stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *myfunc1(void *args) {
    int i = 0;
    for (; i < 500; ++i) {
        putchar('a');
    }

    return NULL;
}

void *myfunc2(void *args) {
    int i = 0;
    for (; i < 500; ++i) {
        putchar('b');
    }

    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    
    pthread_create(&tid1, NULL, myfunc1, NULL);
    pthread_create(&tid2, NULL, myfunc2, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
