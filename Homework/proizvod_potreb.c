#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

char word[256];
sem_t sem;
int n = 0; 
int running = 1;           

void* potreb(void* arg) {
    while (running) {
        sem_wait(&sem); 

        if (!running) break;

        int len = strlen(word);
        for (int i = 0; i < len / 2; i++) {
            char temp = word[i];
            word[i] = word[len - 1 - i];
            word[len - 1 - i] = temp;
        }
        
        printf("Потребитель: %s\n", word);
        
        n = 0; 
    }
    return NULL;
}

int main() {
    pthread_t t;
    
    sem_init(&sem, 0, 0);
    pthread_create(&t, NULL, potreb, NULL);

    while (1) {
        while (n); 

        fgets(word, sizeof(word), stdin);
    

        if (strlen(word) == 1) {
            running = 0;
            sem_post(&sem);
            break;
        }

        n = 1;
       
        sem_post(&sem); 
    }

    pthread_join(t, NULL);
   
    
    return 0;
}