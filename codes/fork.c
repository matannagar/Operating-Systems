int i = 1;

fork_id = fork();
if(fork_id==-1)
{
	perror("cannot fork\n");
	exit(1);
}
else if (fork_id==0)
{
	i = 7;
	printf("child pid %d", getpid());
}
else
{
	printf("parent pid %d", getpid());
}
return 0;