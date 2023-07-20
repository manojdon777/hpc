#include<stdio.h>
#include<omp.h>
#define N 5
int main()
{
	int a =10;
	int b =20;
	int c=0;
	int i;
	omp_set_num_threads(N);
	
	#pragma omp parallel for
	for(i=0; i<5; i++)
	{
//		for(i=0; i<N; i++){
		c += i;
		printf("The thread %d is performing  %d\n", omp_get_thread_num(),i);
//		}	
	}	
return 0;
}
