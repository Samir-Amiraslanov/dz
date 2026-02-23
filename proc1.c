#include <unistd.h>
#include <stdio.h>


int main (){
	pid_t p;
	p=fork();
	printf("frock returned %d\n",p);
	sleep(30);
}
