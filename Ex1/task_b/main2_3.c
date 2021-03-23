#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main(){
	pid_t pid = fork();

	if(pid==0){
		chdir("/"); //change location to root directory. 

		setsid(); //move it to another session, so we can close the parent process.

		printf("starting my daemon\n");

		close(stdout);
		close(stdin);
		close(stderr);

		openlog ("myDaemon",LOG_PID, LOG_DAEMON);
		syslog(LOG_NOTICE,"damon started 2");
		usleep(3000000);
		syslog(LOG_NOTICE,"doing some work...2");
		usleep(3000000);
		syslog(LOG_NOTICE,"daemon finished 2");

	}
	else{
		printf("daemon PID %d\n",pid);
	}
	return 0;
}