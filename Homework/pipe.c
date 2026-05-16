#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];     
    char buf[10];  
    pipe(fd);      
    if (fork() == 0) {
        read(fd[0], buf, 5);      
        printf("Получено: %s\n", buf);
    } else {
        write(fd[1], "Hello", 5);  
    }

    return 0;
}