#include<stdio.h>
#include<omp.h>
#include<time.h>

int main(){

        clock_t start, end;
        double execution_time;
        start = clock();

        int num;
        unsigned long long fact=1;
        int i;
        printf("Enter a number: ");
        scanf("%d", &num);

        #pragma omp parallel num_threads(3)
        {
                #pragma omp for private(i) reduction(*:fact)
                for(i=1; i<=num; i++){
                      printf("Thread (%d) is executing iteration %d.\n", omp_get_thread_num(), i);
                        fact *= i;
                }
        }
        end = clock();
        execution_time = ((double)(end - start))/CLOCKS_PER_SEC;

        printf("Time taken... :%f\n", execution_time);
        printf("\nFactorial is %d.\n",fact);
        return 0;
}
