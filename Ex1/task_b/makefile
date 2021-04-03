FLAGS = -Wall -g

all: task1 task2 task3 task4

task1: main2_1.c
	gcc $(FLAGS) main2_1.c -o main2_1
	
task2: main2_2.c
	gcc $(FLAGS) main2_2.c -o main2_2
	
task3: main2_3.c
	gcc $(FLAGS) main2_3.c -o main2_3

task4: main2_4.c main2_1.c main2_2.c
	gcc $(FLAGS) main2_1.c -o main2_1
	gcc $(FLAGS) main2_2.c -o main2_2
	gcc $(FLAGS) main2_3.c -o main2_2
	gcc $(FLAGS) main2_4.c -o main2_4
	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.exe main2_1 main2_2 main2_3 main2_4

