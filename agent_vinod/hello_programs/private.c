#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
	omp_set_num_threads(4);

	int val1 = 123456789;
	int val2 = 123456789;

	printf("value of \"val1\" before the openMp parallel region:%d.\n",val1);
	printf("value of \"val2\" before the openMp parallel region:%d.\n\n",val2);

#pragma omp parallel private(val2)

	{
		printf("Thread %d sees \"va1l\" =%d, and \"val2\" =%d.\n", omp_get_thread_num(), val1, val2);
		val1 = omp_get_thread_num();
		val2 = omp_get_thread_num();

	}

	printf("\nvalue of \"val1\"after the openMp parallel region: %d.\n", val1);
	printf("value of \"val2\"after the openMp parallel region: %d.\n", val2);
	return 0;
}
