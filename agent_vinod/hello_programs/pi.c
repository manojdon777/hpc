#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main() 
{	
	static long num_step = 1000000;
	double steps;
	int i;
	double Pi, x, sum=0.0;
	steps = 1.0/(double)num_step;
	for(i=0; i<num_step; i++)
	{
		x=(i) *steps;
		sum = sum + 4.0/(1.0 + x*x);
//		printf("Thread %d is performing %d iteration.\n",omp_get_thread_num(), i);	
	}
	
	Pi = steps* sum;
	printf("Estimated Value of Pi is %f.\n", Pi);
	return 0;	
}
