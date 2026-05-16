#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> 

void mysignal(int signum) {
    printf("сигнал %d \n", signum);
}
int main() {
    signal(SIGINT, mysignal);
    while(1) {
        printf(".\n");
        sleep(2);
    }
    return 0;
}