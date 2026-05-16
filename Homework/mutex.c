#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int shared_counter = 0;
pthread_mutex_t mutex; 
void *tFunc(void *arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);   
        shared_counter++;            
       pthread_mutex_unlock(&mutex); 
    }
    return NULL;
}

int main(void) {
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL); 

    pthread_create(&t1, NULL, tFunc, NULL);
    pthread_create(&t2, NULL, tFunc, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Итоговый счетчик: %d\n", shared_counter); 
    return 0;
}