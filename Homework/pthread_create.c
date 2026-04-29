#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *tFunc(void *arg) 
{
    sleep(200);
    printf("Вывод из потока\n");
    return NULL;
}

int main(void) 
{
    pthread_t tchild;

    pthread_create(&tchild, NULL, tFunc, NULL);
    printf("Ждем окончания потока\n");
    pthread_join(tchild, NULL);

    return 0;
}