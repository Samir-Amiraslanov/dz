#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;
void *thread1_func(void *arg) {
    printf("Поток 1 старт\n");
    sleep(1); 
    printf("Поток 1 конец\n");
    
    sem_post(&sem); 
    return NULL;
}

void *thread2_func(void *arg) {
    printf("Поток 2: Ждет завершения Потока 1\n");
    
    sem_wait(&sem); 
    printf("Поток 2 продолжаает работу\n");
    return NULL;
}

int main(void) {
    pthread_t t1, t2;
    sem_init(&sem, 0, 0); 

    pthread_create(&t2, NULL, thread2_func, NULL); 
    pthread_create(&t1, NULL, thread1_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}