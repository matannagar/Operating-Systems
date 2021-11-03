N=2; //num of processes
int interested[N];
interested[0]=interested[1]=FALSE;
int turn; //turn

//				  process can be 0 or 1
void enter_region(int process)
{
	int other = 1- process; // the other process
	interested[process] = TRUE; //curr process is interested
	turn = process; //my turn now
	//curr process is letting the other process run until he exsits
	while ( turn == process && interested[other]); 
	/*
	if we were to change the while loop 
	while ( turn != process && interested[other]); this would mean I am not letting the other process run, I am first 
	*/

void leave_region(int process)
{
	interested[process] = FALSE;
}