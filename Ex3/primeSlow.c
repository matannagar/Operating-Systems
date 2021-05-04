#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 5
#define run_n 10000

pthread_mutex_t lock;
long sum = 0;
long primeCounter = 0;
int count = 0;

int isPrime(int num)
{
	if (num <= 3)
		return num > 1;

	if ((num % 2 == 0) || (num % 3 == 0))
		return 0;
	int count = 5;

	while (pow(count, 2) <= num)
	{
		if (num % count == 0 || num % (count + 2) == 0)
			return 0;
		count += 6;
	}
	return 1;
}

void *func(void *var)
{
	for (int i = 0; i < 2000; ++i)
	{
		int random = rand();
		if (isPrime(random))
		{
			sum = sum + random;
			primeCounter++;
		}
		pthread_mutex_lock(&lock);
		count++;
		if (count==run_n) return 0;
		pthread_mutex_unlock(&lock);
	}
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
	int numOfRandomNumbers = atoi(argv[2]);

	//init rundom generator
	int random;
	pthread_t threads[NUM_THREADS];
	void *retvals[NUM_THREADS];
	srand(randomPivot);

	for (int i = 0; i < NUM_THREADS; ++i)
	{
		if (pthread_create(&threads[i], NULL, func, (void *)&randomPivot) != 0)
		{
			fprintf(stderr, "error: Cannot create thread # %d\n", i);
			break;
		}
	}
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			fprintf(stderr, "error: Cannot join thread # %d\n", i);
		}
	}

	printf("%ld,%ld\n", sum, primeCounter);
	pthread_mutex_destroy(&lock);
	exit(0);
}

/*
  pthread_t threads[NTHREADS];
  void * retvals[NTHREADS];
  int count;
  for (count = 0; count < NTHREADS; ++count)
    {
      if (pthread_create(&threads[count], NULL, thread_func, "...") != 0)
        {
          fprintf(stderr, "error: Cannot create thread # %d\n", count);
          break;
        }
    }
  for (int i = 0; i < count; ++i)
    {
      if (pthread_join(threads[i], &retvals[i]) != 0)
        {
          fprintf(stderr, "error: Cannot join thread # %d\n", i);
        }
    }
*/
