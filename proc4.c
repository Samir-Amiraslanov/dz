#include <stdio.h>
#include <unistd.h>
int main (void) {

    char *arg[] = { "/bin/ls", "-l", 0 };
    if (fork() == 0) {
        printf("In child process:\n");
        execv(arg[0], arg);
        printf("I will never be called\n");
    }

    sleep(5);
    return 0;

}
