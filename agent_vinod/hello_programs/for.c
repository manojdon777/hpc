#include<stdio.h>
#include<omp.h>

int main(){

	printf("Start of the program...\n");

	#pragma omp parallel num_threads(10)
	{
	int ID = omp_get_thread_num();
	printf("helolo %d\n",ID);
	}
	

	#pragma omp parallel
	{
	printf("sdfjsd\n");
	}

	return 0;
}
