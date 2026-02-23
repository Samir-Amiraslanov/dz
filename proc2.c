#include <unistd.h>
#include <stdio.h>
int main (){
	pid_t p;
	printf("Origin program,pid=%d\n",getpid());
	p=fork();
	if(p==0){
		printf("In child process , pid=%d ppid=%d\n",getpid(),getppid());
	} else {
				printf("In parent, pid=%d, fork returned=%d\n",getpid(),p);
				sleep(2);
		}
}
