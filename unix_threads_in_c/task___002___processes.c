#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/*
 * Создание двух процессов, которые выводят свой pid (process id) и дочерний 
 * процесс инкреминирует переменную `x`.
 * 
 * При выполнение программы видно, что pid (process id) потоков разный, что
 * говорит о том, что это разные потоки (как удивительно).
 * 
 * Переменная `x` при этом выводится с разными значениями, что значит,
 * что дочерний поток имеет копию памяти родительского, а значит они не
 * разделяют общую память.
 */

int main(int argc, char** argv) {
    int x = 2;

    int pid = fork();
    if (pid == -1) {
        return -1;
    }

    printf("Hello from process with %d pid\n", getpid());

    if (pid == 0) {
        // This is child process, increment `x`
        x++;
    }
    sleep(2);
    printf("Value of x: %d\n", x);

    if (pid != 0) {
        wait(NULL);
    }

    return 0;
}