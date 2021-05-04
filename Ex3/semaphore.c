#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#include <semaphore.h>

pthread_t tid[2];
int counter = 0;
pthread_mutex_t lock;

sem_t mutex;

void* doSomeThing(void *arg)
{
    //pthread_mutex_lock(&lock);
    sem_wait(&mutex); //wait state

    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d started\n", counter);

    for(i=0; i<(0xFFFFFFFF);i++);

    printf("\n Job %d finished\n", counter);

    //pthread_mutex_unlock(&lock);
    sem_post(&mutex);

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;
    int numOfThreads = 10;

    //if (pthread_mutex_init(&lock, NULL) != 0)
    //{
    //    printf("\n mutex init failed\n");
    //    return 1;
    //}

    sem_init(&mutex, 0, 4); // - "0 - permissions", "1 - counter"

    while(i < numOfThreads)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    i = 0;
    while(i < numOfThreads)
    {
         pthread_join(tid[i], NULL);
	 i++;
    }

    //pthread_mutex_destroy(&lock);
    sem_destroy(&mutex);

    return 0;
}
