#processes numbered from 0 to N-1
#num is an array of N integers, each assigned to a process

lock(i)
{
	//what would happen if this line was not atomic?
	//2 processes might get the same value and break the mutual exclusion
	num[i] = MAX(num[0],num[1],...,num[N-1])+1;

	for(int p = 0; p<N; p++)
	{
	while(num[p]!=0 && num[p]<num[i])
		{
			//if num[p] == 0 it means he is done
			//waiting in line because num[i] is bigger than other processes
		};
	}
}

//done working
unlock(i)
{
	num[i]=0;
}