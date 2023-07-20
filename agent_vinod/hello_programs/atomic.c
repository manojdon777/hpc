#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char*argv[])
{	
	int i;
	int total = 0;	
	omp_set_num_threads(4);
	
	#pragma omp parallel default(none) private(i) shared(total)
	{
		for (i =0; i<10; i++)
		{
			printf("This iteration (%d) is being executed by thread (%d) and total is (%d).\n",i,omp_get_thread_num(),total);
			#pragma omp atomic
			total++;
		}
	}
	printf("Total =%d\n",total);
	return 0;
} 
