#include<stdio.h>
#include<omp.h>

int main(){
	
	#pragma omp parallel num_threads(10)
	{
	int ID = omp_get_thread_num();
	printf("Thread running this print statement is ---%d.\n",ID);
	}

	return 0;
}
