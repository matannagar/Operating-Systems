#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

#define MAX 2147483646
char *primes;

int *amount;
int *num_of_threads;
pthread_mutex_t lock;
long sum = 0;
long primeCounter = 0;

int isPrime(int num)
{
	// if (primes[num - 1])
	// 	return 1;

	// else
	// {
		if (num <= 1)
			return 0;
		if (num <= 3){
			primes[num-1]=1;
			return 1;
			}
		if (num % 2 == 0 || num % 3 == 0)
			return 0;
		int sqr = sqrt(num);
		for (int i = 5; i <= sqr; i = i + 6)
		{
			if (num % i == 0 || num % (i + 2) == 0)
				return 0;
		}
		primes[num-1]=1;
		return 1;
	// }
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

// void *func1()
// {
// 	// for (int i = 0; i < MAX * 0.25; i++)
// 	// {
// 	// 	primes[i] = 0;
// 	// }

// 	int limit = (sqrt(MAX) + 1) * 0.25;

// 	for (long long i = 2; i < limit; i++)
// 	{
// 		if (primes[i - 1])
// 		{
// 			for (long long j = i * i; j <= MAX; j += i)
// 			{
// 				// pthread_mutex_lock(&lock);
// 				primes[j - 1] = 0;
// 				// pthread_mutex_unlock(&lock);
// 			}
// 		}
// 	}

// 	return NULL;
// }

// void *func2()
// {
// 	// for (int i = MAX * 0.25; i < MAX * 0.5; i++)
// 	// {
// 	// 	primes[i] = 0;
// 	// }
// 	int limit = (sqrt(MAX) + 1) * 0.5;

// 	for (long long i = MAX * 0.25; i < limit; i++)
// 	{
// 		if (primes[i - 1])
// 		{
// 			for (long long j = i * i; j <= MAX; j += i)
// 			{
// 				pthread_mutex_lock(&lock);
// 				primes[j - 1] = 0;
// 				pthread_mutex_unlock(&lock);
// 			}
// 		}
// 	}

// 	return NULL;
// }

// void *func3()
// {
// 	// for (int i = MAX * 0.5; i < MAX * 0.75; i++)
// 	// {
// 	// 	primes[i] = 0;
// 	// }

// 	int limit = (sqrt(MAX) + 1) * 0.75;

// 	for (long long i = MAX * 0.5; i < limit; i++)
// 	{
// 		if (primes[i - 1])
// 		{
// 			for (long long j = i * i; j <= MAX; j += i)
// 			{
// 				pthread_mutex_lock(&lock);
// 				primes[j - 1] = 0;
// 				pthread_mutex_unlock(&lock);
// 			}
// 		}
// 	}

// 	return NULL;
// }

// void *func4()
// {
// 	// for (int i = MAX * 0.75; i < MAX; i++)
// 	// {
// 	// 	primes[i] = 0;
// 	// }

// 	int limit = (sqrt(MAX) + 1);

// 	for (long long i = MAX * 0.75; i < limit; i++)
// 	{
// 		if (primes[i - 1])
// 		{
// 			for (long long j = i * i; j <= MAX; j += i)
// 			{
// 				pthread_mutex_lock(&lock);
// 				primes[j - 1] = 0;
// 				pthread_mutex_unlock(&lock);
// 			}
// 		}
// 	}
// 	return NULL;
// }

int main(int argc, char *argv[])
{
	// primes = malloc((MAX + 1) * sizeof(char));
	// primes[MAX]={0};

	// pthread_t t1, t2, t3, t4;
	// pthread_create(&t1, NULL, &func1, NULL);
	// pthread_create(&t2, NULL, &func2, NULL);
	// pthread_create(&t3, NULL, &func3, NULL);
	// pthread_create(&t4, NULL, &func4, NULL);

	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);
	// pthread_join(t3, NULL);
	// pthread_join(t4, NULL);
	// for (int i = 0; i < MAX; i++)
	// {
	// 	primes[i] = 0;
	// }

	/* Loop through a portion of the array (up to the square root of MAX). If
   * it's a prime, ensure all multiples of it are set to zero (false), as they
   * clearly cannot be prime.
   */
	// int limit = sqrt(MAX) + 1;
	// for (long long i = 2; i < limit; i++)
	// {
	// 	if (primes[i - 1])
	// 	{
	// 		for (long long j = i * i; j <= MAX; j += i)
	// 		{
	// 			primes[j - 1] = 0;
	// 		}
	// 	}
	// }

	long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);
	num_of_threads = malloc(number_of_processors * sizeof(int));
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
	free(num_of_threads);
	
	pthread_mutex_destroy(&lock);
	printf("%ld,%ld\n", sum, primeCounter);
	// pthread_exit(NULL);
	exit(0);
}
