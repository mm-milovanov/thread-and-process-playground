#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 * Создание двух примитивных потоков которые выводят id своего процесса и один
 * из них инкреминирует переменную `x`.
 * 
 * Как видно при выполнение программы их pid (process id) одинаковые, что
 * значит, что оба потока принадлежат одному процессу.
 * 
 * Переменная `x` при этом выводится с одинаковым значением обоими потоками,
 * что значит, что потоки разделяют общую память, в отличие от процессов.
 */

int x = 2;

void* routine() {
    printf("Hello from thread with %d pid\n", getpid());
    x++;
    sleep(2);
    printf("Value of x: %d\n", x);
}

void* routine2() {
    printf("Hello from thread with %d pid\n", getpid());
    sleep(2);
    printf("Value of x: %d\n", x);
}

int main(int argc, char** argv) {
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0) {
        return -1;
    }
    if (pthread_create(&t2, NULL, &routine2, NULL) != 0) {
        return -2;
    }
    if (pthread_join(t1, NULL) != 0) {
        return -3;
    }
    if (pthread_join(t2, NULL) != 0) {
        return -4;
    }

    return 0;
}