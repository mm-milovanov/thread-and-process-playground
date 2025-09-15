#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 * Пример Race Condition. Результатом выполнения программы должно быть 
 * 2'000'00. Однако, если выполнить программу, то будет произвольное число,
 * которое будет иметь меньшее значение, от того которое должно быть.
 * 
 * Проблема заключается в том, что ОС может заморозить один из потоков
 * который уже записал в регистр ЦП значение переменной mails. Второй,
 * продолжая работу, инкременирует значение mails, но когда размораживается 
 * первый поток, то он перезаписывает переменную mails на инкременированное,
 * запомненное им значение из регистра ЦП, что ведёт к тому, что всё, что
 * инкременнировал первый поток, пока был заморожен второй, "забывается".
 */

int mails = 0;

void* routine() {
    for (int i=0; i<1000000; i++)
        mails++;
}

int main(int argc, char** argv) {
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return -1;
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
        return -2;
    if (pthread_join(t1, NULL) != 0)
        return -3;
    if (pthread_join(t2, NULL) != 0)
        return -4;

    printf("Number of mails: %d\n", mails);

    return 0;
}