#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 * Создание одного примитивного потока.
 */

void* routine() {
    printf("Test from threads\n");
}

int main(int argc, char** argv) {
    pthread_t t1;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    return 0;
}