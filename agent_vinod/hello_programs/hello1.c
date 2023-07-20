#include<stdio.h>
#include<omp.h>
int main()
{
	printf("Hello HPCAP\n");
//	omp_set_num_threads(10);
//	#pragma omp parallel num_threads(8)
	#pragma omp parallel
		{
	printf("Hello parallel region\n");
		}
return 0;
}
