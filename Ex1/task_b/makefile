FLAGS = -Wall -g

all: task1 task2 task3

task1: main2_1.c
	gcc $(FLAGS) main2_1.c -o Subtask1
	./Subtask1
	
task2: main2_2.c
	gcc $(FLAGS) main2_2.c -o Subtask2
	./Subtask2
	
task3: main2_3.c
	gcc $(FLAGS) main2_3.c -o Subtask3
	./Subtask3
	grep myDaemon /var/log/syslog
	

.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.exe Subtask1 Subtask2 Subtask3

