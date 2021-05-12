#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>

#define TABLE_SIZE      ((INT_MAX/CHAR_BIT/sizeof(int)/2)+1)
#define BITS_PER_ENTRY  (sizeof(int)*CHAR_BIT)

// Halve the length of the table by only storing odd results
// 2 is a special case.
// If the bit is clear, it's a prime
unsigned int table[TABLE_SIZE] = { 0 };

pthread_mutex_t lock;
long sum = 0;
long primeCounter = 0;

// map 1,3,5,7,9 etc to 0,1,2,3,4
int valueToIndex(int value)
{
  int result = value / 2;
  return result;
}

void setComposite(int composite)
{
  if (composite % 2 == 0)
    return;
  int value = valueToIndex(composite);
  int pos = value / BITS_PER_ENTRY;
  int bit = value % BITS_PER_ENTRY;
  unsigned int mask = 1u << bit;
  table[pos] |= mask;
}

#ifdef USE_LOOKUP
int isPrime(int number)
{
  if (number <= 2)
    return 1;
  if (number % 2 == 0)
    return 0;
  int value = valueToIndex(number);
  int pos = value / BITS_PER_ENTRY;
  int bit = value % BITS_PER_ENTRY;
  unsigned int mask = 1u << bit;
  return (table[pos] & mask) == 0;
}
#else
int isPrime(int num)
{
  if (num <= 1)
    return 0;
  if (num <= 3)
    return 1;
  if (num % 2 == 0 || num % 3 == 0)
    return 0;

  int limit = sqrt(num);
  for (int i = 5; i <= limit; i = i + 6)
  {
    if (num % i == 0 || num % (i + 2) == 0)
      return 0;
  }
  return 1;
}
#endif

int nextCandidatePrime(int p)
{
  do {
    p += 2;                     // the next odd number
  } while (!isPrime(p));
  return p;
}

void createPrimeTable(int limit)
{
  int s = sqrt(limit);
  for (int p = 3; p < s; p = nextCandidatePrime(p)) {
    int end = limit - p;
    for (int c = p * p; c < end; c += p) {
      setComposite(c);
    }
  }
}

typedef struct {
  unsigned int seed;
  int limit;
} funcdata_st;

void *func(void *p)
{
  funcdata_st *info = (funcdata_st *) p;
  long local_sum = 0, local_counter = 0, count = 0;
  for (int i = 0; i < info->limit; ++i) {
    int random = rand_r(&info->seed); //!! NB - using rand_r !!
    if (isPrime(random)) {
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
  //make sure enough arguments were received
  if (argc != 3) {
    printf("Too few arguments ");
    printf("USAGE: ./primeCalc <prime pivot> <num of random numbers>");
    exit(0);
  }
#ifdef USE_LOOKUP
  createPrimeTable(INT_MAX);
  printf("Table built\n");
#endif

  long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);
  int randomPivot = atoi(argv[1]);
  int numOfRandomNumbers = atoi(argv[2]);

  //creating thread
  pthread_t threads[number_of_processors];
  funcdata_st info[number_of_processors];

  pthread_mutex_init(&lock, NULL);
  for (int i = 0; i < number_of_processors; ++i) {
    info[i].seed = randomPivot + i; // makes no sense for all threads to generate the same sequence
    info[i].limit = numOfRandomNumbers / number_of_processors;
    if (pthread_create(&threads[i], NULL, func, &info[i]) != 0) {
      fprintf(stderr, "error: Cannot create thread # %d\n", i);
      break;
    }
  }
  for (int i = 0; i < number_of_processors; ++i) {
    if (pthread_join(threads[i], NULL) != 0) {
      fprintf(stderr, "error: Cannot join thread # %d\n", i);
    }
  }

  pthread_mutex_destroy(&lock);
  printf("%ld,%ld\n", sum, primeCounter);
  pthread_exit(NULL);
}