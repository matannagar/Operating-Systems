#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100000
char child_stack[STACK_SIZE+1];

void print(const char *who){
	for(int i=0; i< 1000;i++){
		printf("Running %s\n",who);
		usleep(1000000);
	}
}
int child(void *params){
	print("child_thread");
	return 0;
}

int main(){

	int result = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
	int result2 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);

	printf("clone result= %d\n",result);
printf("clone result= %d\n",result2);
	print("parent");

	return 0;
}