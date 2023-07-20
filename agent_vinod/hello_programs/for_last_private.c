#include<stdio.h>
#include<omp.h>
#define N 5
int main()
{
	int a = 10;
	int b = 20;
	int c = 321;
	omp_set_num_threads(N);
	#pragma omp parallel for lastprivate(c)
	for (int i=0; i<N; i++)
	{
	printf("The thread %d value is %d\n", omp_get_thread_num(),c);
	
	if(omp_get_thread_num()%2==0){
	c = a + b;
	}
	else{
	c = 1000;
	}	

	printf("The thread %d value is %d\n", omp_get_thread_num(),c);
	}


printf("End of prallel region\n\n");

printf("The thread %d value is %d\n", omp_get_thread_num(), c);
return 0;
}


