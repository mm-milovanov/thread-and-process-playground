#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 * Создание двух примитивных потоков выполняющихся друг за другом.
 */

void* routine() {
    printf("Test from threads\n");
}

int main(int argc, char** argv) {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}