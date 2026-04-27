#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while(1) {
        pid_t pid = fork();
        
        printf("boom %d\n", pid);
    }
    return 0;
}