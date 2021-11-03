init(S)
{
	S=N; // num of simutaneously allowed processess in CS;
}

down(S)
{
	S--;
	while(S<0);
}

up(S)
{
	S++;
	if(S<=0) {wake up process;}
}

/*
the advantage of a negative semaphore is that we can count how many blocked processes = -S;
*/