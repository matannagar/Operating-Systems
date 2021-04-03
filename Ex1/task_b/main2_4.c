#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100000
char child_stack[STACK_SIZE+1];


int Subtask1(void *params){
	char * args[2] = {"./main2_1",NULL}; 
	execv(args[0],args);
	return 0;
}

int Subtask2(void *params){
	char * args[2] = {"./main2_2",NULL}; 
	execv(args[0],args);
	return 0;
}

int Subtask3(void *params){
	char * args[2] = {"./main2_3",NULL}; 
	execv(args[0],args);
	return 0;
}

int main(){

	int result1 = clone(Subtask1,child_stack+STACK_SIZE,CLONE_PARENT,0);
	int result2 = clone(Subtask2,child_stack+STACK_SIZE,CLONE_PARENT,0);
	int result3 = clone(Subtask3,child_stack+STACK_SIZE,CLONE_PARENT,0);


	return 0;
}