
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

void print(const char *who){
	for(int i=0;i<10;i++){
		printf("Running %s process\n",who);
		usleep(1000000);
	}
}
int main(){
	pid_t pid = fork(); //creating a child

	if (pid == 0){
		//we are in child
		pid_t pid = fork(); // creating grandchild

		if(pid == 0){
			//we are in grandchild
			print("process2");
		}
		else{
			print("process1");
		}
	}
	else{
		print("App");
	}
	return 0;
}