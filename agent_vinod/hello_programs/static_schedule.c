#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc, char* argv[])
{
	int i;
	omp_set_num_threads(4);
	
	printf("With no chunksize passed:\n");
	#pragma omp parallel for schedule(static,4) ordered
	for (i = 0; i < 20; i++)
	{
		printf("Thread %d processes iteration %d.\n", omp_get_thread_num(),i);
	}
	printf("With a chunksize of 2:\n");
	
	#pragma omp parallel for schedule(guided, 4) //ordered
	for (i = 0; i< 22; i++)
	{
		printf("Thread %d processes iteration %d.\n", omp_get_thread_num(), i);
	}
	
	return 0;
}


