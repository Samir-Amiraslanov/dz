#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	
	pid_t p;
	int *a;
	
	a=(int*)malloc(10*sizeof(int));
	for(int i=0;i<10;i++) a[i]=i;
	printf("Original program, pid=%d\n", getpid());
	p=fork();
	if(p==0){
		printf("In child process, pid=%d, ppid=%d\n",
		getpid(), getppid());
		for(int i=0;i<10;i++) a[i]++;
		for(int i=0;i<10;i++)  printf("%d\n",a[i]);
	}
	else{
		printf("In parent, pid=%d, fork returned=%d\n",
		getpid(), p);
		
		for(int i=0; i<10; i++) a[i]--;
		for(int i=0;i<10;i++) printf("%d\n", a[i]);
		
		
	}
	
	
}
