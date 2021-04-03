
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

void print(const char *who){
	for(int i=0;i<100;i++){
		printf("Running %s process\n",who);
		usleep(1000000);
	}
}

void create_process(){
	id_t pid = fork(); //creating a child

	if (pid == 0){
		//we are in child
		pid_t pid = fork(); // creating grandchild

		if(pid == 0){
			//we are in grandchild
			print("main2_1: Grandchild");
		}
		else{
			print("main2_1: Child");
		}
	}
	else{
		print("main2_1: Parent");
	}
}

int main(){

create_process();

	return 0;
}