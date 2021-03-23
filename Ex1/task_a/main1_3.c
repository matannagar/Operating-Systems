#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*printGreeting)();

bool init_library(){
	void *hdl = dlopen("./libHello.so",RTLD_LAZY);
	if (NULL==hdl){
		return false;
	}
	printGreeting=(void(*)())dlsym(hdl,"printGreeting");
	if(NULL==printGreeting){
		return false;
	}
	return true;
}

int main(){
	if (init_library()){
		printGreeting();
	}
	else{
		printf("Library was not loaded\n");
	}
	return 0;
}