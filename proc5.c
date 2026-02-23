#include <unistd.h>
#include <stdio.h>


int global ;

int main() {
    int local;
    pid_t p;

    p = fork();


    if (p == 0) {
        global = 555;
        local = 999;
        printf(" Глобальная: %d , Локальная: %d \n", global, local );
    } 
    else {
        sleep(1); 
        printf(" Глобальная: %d , Локальная: %d \n", global,  local);
        
      
    }

    return 0;
}
