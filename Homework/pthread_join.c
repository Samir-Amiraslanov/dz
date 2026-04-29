#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void f()
{
    int a=5, c=6;
    int s=a+c;
    printf("%d + %d = %d\n",a,c,s);
}
void *tFunc(void *arg) 
{
    f();
    static int ret = 42; 
    printf("Hello from Thread!\n");
    return &ret;
}

int main(void) 
{

    pthread_t tchild;
    void *status;

    pthread_create(&tchild, NULL, tFunc, NULL);
    pthread_join(tchild, &status);

    printf("%d\n", *(int*)status);

    return 0;
}