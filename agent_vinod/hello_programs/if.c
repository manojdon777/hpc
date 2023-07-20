#include<stdio.h>
#include<omp.h>
int main(){
#pragma omp parallel if(5<6) num_threads(7)
{
	printf("The threads is %d\n",omp_get_thread_num());
}
return 0;
}
