#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <sys/types.h>

#define NUM_THREADS 5
#define run_n 10000000

pthread_mutex_t lock;
long sum = 0;
long primeCounter = 0;
int count = 0;

int isPrime(int num)
{
	if (num <= 1)
		return 0;
	if (num <= 3)
		return 1;
	if (num % 2 == 0 || num % 3 == 0)
		return 0;
	int sqr = sqrt(num);
	for (int i = 5; i <= sqr; i = i + 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return 0;
	}
	return 1;
}

void *func(void *var)
{
	srand(*((int*)var));
    long local_sum = 0, local_counter = 0;
    unsigned int seed = 6;  //!! use your var in some way
    for (int i = 0; i < run_n / NUM_THREADS; ++i)
    {
        // int random = rand_r(&seed);
        int random = rand();
        if (isPrime(random))
        {
            local_sum += random;
            local_counter++;
        }
    }
    pthread_mutex_lock(&lock);
    sum += local_sum;
    primeCounter += local_counter;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;

	if (argc != 3)
	{
		printf("Too few arguments ");
		printf("USAGE: ./primeCalc <prime pivot> <num of random numbers>");
		exit(0);
	}

	int randomPivot = atoi(argv[1]);
	// int numOfRandomNumbers = atoi(argv[2]);

	//init rundom generator
	int random;
	pthread_t threads[NUM_THREADS];
	srand(randomPivot);

	///////////////////////////////////////////////////////////////
	// id_t pid = fork(); //creating a child

	// if (pid == 0)
	// {
	// 	//we are in child
	// 	pid_t pid = fork(); // creating grandchild

	// 	if (pid == 0)
	// 	{
	// 		//we are in grandchild
	// 		func(&randomPivot);
	// 		if (pid == 0)
	// 		{
	// 			//we are in grandchild
	// 			func(&randomPivot);
	// 		}
	// 		else
	// 		{
	// 			func(&randomPivot);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		func(&randomPivot);
	// 	}
	// }
	// else
	// {
	// 	func(&randomPivot);
	// }
	/////////////////////////////////

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		if (pthread_create(&threads[i], NULL, &func, (void *)&randomPivot) != 0)
		{
			fprintf(stderr, "error: Cannot create thread # %d\n", i);
			break;
		}
		else
		{
			printf("thread %d was created\n", i);
		}
	}
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			fprintf(stderr, "error: Cannot join thread # %d\n", i);
		}
	}
	pthread_mutex_destroy(&lock);
	printf("%ld,%ld\n", sum, primeCounter);
	// pthread_exit(NULL);
	exit(0);
}
