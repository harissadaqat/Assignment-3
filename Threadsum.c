#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * sum(void *arg)
{
	int start = (int)arg,cal = 0;
	for(int i = start;i<start+100;i++)
	{
		cal = cal + i;
	}
	return ((void*)cal);
}

int main ()
{
	pthread_t thread_t[10];
	int result;
	int count = 0,total =0;
	for(int i=0;i<1000;i=i+100){	
		pthread_create(&thread_t[count],NULL,sum,(void*)(i));
		count++;
	}
	for(int i=0;i<10;i++){	
		pthread_join(thread_t[i],(void**) &result);
		total = total + result;	
	}
	printf("Sum of 1000 numbers returned by 10 threads : %d\n", total);

	return 0;
}
