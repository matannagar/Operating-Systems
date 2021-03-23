FLAGS = -Wall -g

all: task1 task2 task3

task1: main1_1.c hello_ariel.c hello_ariel.h
	gcc $(FLAGS) main1_1.c hello_ariel.c -o hello1
	./hello1
	
task2: main1_2.c hello_ariel.h lib export_
	gcc $(FLAGS) main1_2.c -L. -l Hello -o hello2
	./hello2
	
task3: lib hello_ariel.h main1_3.c export_
	gcc $(FLAGS) main1_3.c -fPIC -ldl -o hello3
	./hello3
	make clean
	
lib: hello_ariel.h hello_ariel.c
	gcc -shared hello_ariel.c -fPIC -o libHello.so

export_:
	export LD_LIBRARY_PATH=.


.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.exe hello1 hello2 hello3

