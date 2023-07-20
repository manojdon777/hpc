#include<stdio.h>
#include<omp.h>

int main(){
	
	printf("Hello World...!!!\n");

	#pragma  omp parallel  num_threads(5)
	{
		printf("Hello Parallel Region...(%d)\n",omp_get_thread_num());
		
		#pragma omp barrier	
		#pragma omp parallel num_threads(5)
		{
			
			printf("Vinit....(%d)\n", omp_get_thread_num());
			printf("%d", omp_get_nested());
		}
	}

	return 0;
}
