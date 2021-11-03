#define N 5 //num of philosophers
#define LEFT (i+N-1)%N // num of i left neighbor
#define RIGHT (i+1)%N //num of i right neighbor
#define THINKING 0 // waiting
#define HUNGRY 1 //ready
#define EATING 2 //working

typedef int semaphore;
int state[N]; // THINKING || HUNGRY || EATING
semaphore mutex = 1; //create mutex
semaphore s[N]; //one semaphore per philosopher


//ready state
void take_forks(int phil)
{
	down(&mutex); //enter !!!critical section!!!
	state[phil] = HUNGRY; // curr phil is hungry
	test(phil); // try to aquire 2 forks
	up(&mutex); // exit !!!critical section!!!
	down(&s[phil]); 
}

//finished with cpu || done
void put_forks(int phil)
{
	down(&mutex); // enter critical section
	state[phil] = THINKING; // done eating
	//check if left/right neighbor can eat
	test(LEFT);
	test(RIGHT);
	up(&mutex); //leave critical area
}

//ready to take two forks
void test(int phil)
{
	/*
	if my left and right neihbors are not eating
	then the right fork and left forks are free
	*/
	if (state[phil] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) // both forks are free!
	{
		state[phil] = EATING; //working ! 
		up(&s[phil]); //done working, leaving critical section
	}
}
void philosopher(int philosopher_id)
{
	while (TRUE)
	{
		think(); 
		take_forks(philosopher_id); //trying to get access 
		eat(); //doing work
		put_forks(philosopher_id); //done working
	}
}