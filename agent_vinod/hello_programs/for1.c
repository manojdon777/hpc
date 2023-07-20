#include<stdio.h>
#define N 10
#include<omp.h>
int main()
{
	int a = 10;
	int b = 20;
	int c , i ;

#pragma omp parallel num_threads(4) private(i)
	for(i = 0; i< N; i++){
	c = a+b;
	printf("The thread %d is performing %d iteration\n",omp_get_thread_num(),i);
	}
return 0;
}

