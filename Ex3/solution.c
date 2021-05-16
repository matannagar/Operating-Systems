#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

int *amount;
int *num_of_threads;
pthread_mutex_t lock;
long sum = 0;
long primeCounter = 0;

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

void *func()
{
	long local_sum = 0, local_counter = 0, count = 0;
	int limit = (*amount) / (*num_of_threads);
	for (int i = 0; i < limit; ++i)
	{
		int random = rand();
		if (isPrime(random))
		{
			local_sum += random;
			local_counter++;
			count++;
			if (count == (*amount) / (*num_of_threads))
				return NULL;
		}
	}
	pthread_mutex_lock(&lock);
	sum += local_sum;
	primeCounter += local_counter;
	if (count == (*amount))
		return NULL;
	pthread_mutex_unlock(&lock);
	return NULL;
}

int main(int argc, char *argv[])
{
	long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);
	num_of_threads = malloc( number_of_processors * sizeof(int));
	*num_of_threads = number_of_processors;

	//make sure enough arguments were received
	if (argc != 3)
	{
		printf("Too few arguments ");
		printf("USAGE: ./primeCalc <prime pivot> <num of random numbers>");
		exit(0);
	}
	//receive arguments from user
	int randomPivot = atoi(argv[1]);
	int numOfRandomNumbers = atoi(argv[2]);
	amount = malloc(numOfRandomNumbers * sizeof(int));
	*amount = numOfRandomNumbers;

	//creating thread
	pthread_t threads[*num_of_threads];
	srand(randomPivot);
	//creating multiple threads , executing our function
	for (int i = 0; i < *num_of_threads; ++i)
	{
		if (pthread_create(&threads[i], NULL, &func, NULL) != 0)
		{
			fprintf(stderr, "error: Cannot create thread # %d\n", i);
			break;
		}
	}
	for (int i = 0; i < *num_of_threads; ++i)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			fprintf(stderr, "error: Cannot join thread # %d\n", i);
		}
	}
	free(amount);
	pthread_mutex_destroy(&lock);
	printf("%ld,%ld\n", sum, primeCounter);
	// pthread_exit(NULL);
	exit(0);
}
