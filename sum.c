#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	int arr[1000],checkID;
	int num=0,returned;
	int numPipe[2];
    	pipe(numPipe);

	for(int Counter=0;Counter<1000;Counter++)
	{
		arr[Counter]=Counter;
	}	

	for(int k=0;k<1000;k=k+100)
	{
		checkID = fork();
		if(checkID == 0){
			int sum=0;
			for(int j = k; j< k+100;j++){
				sum = sum + arr[j];
			}
			write(numPipe[1],&sum,sizeof(sum));
			exit(0);
		}
		wait(NULL);
		read(numPipe[0],&returned,sizeof(returned));
		num = num + returned;
	}	
	printf("SUM IS : %d",num);
	
}
