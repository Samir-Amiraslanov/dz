#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t f = fork();

    if (f == 0) {
        printf("\n");
        return 1; 
    } else {
        int status;
        wait(&status); 
        printf("Родитель: Ребенок завершился с кодом %d\n", WEXITSTATUS(status));
        printf("%d\n",status);
        
    }
    return 0;
}