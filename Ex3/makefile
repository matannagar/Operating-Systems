FLAGS = -Wall -g

all: solution

solution: solution.c
	gcc $(FLAGS) solution.c -o solution -lpthread -lm
	

	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.exe solution