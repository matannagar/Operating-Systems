lock(i)
{
	//choosing ensures that a process is not at the doorway
	choosing[i] = TRUE;
	num[i] = MAX(num[0],num[1]...,num[N-1])+1;
	choosing[i] = FALSE;

	for(int p=0; p<N; p++)
	{	//i.e the process is not currently choosing a value for num
		while(choosing[p]);
		//favor one process if there is a conflic: (a,b) < (c,d) : (a<c) || ((a==c) && (b<d))
		while(num[p]!=0 && (num[p],p) < (num[i],i);
	}
}

unlock(i)
{
	num[i] =0;
}