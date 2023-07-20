/* File:  
 *    pth_hello.c
 *
 * Purpose:
 *    Illustrate basic use of pthreads:  create some threads,
 *    each of which prints a message.
 *
 * Input:
 *    none
 * Output:
 *    message from each thread
 *
 * Compile:  gcc -g -Wall -o pth_hello pth_hello.c -lpthread
 * Usage:    ./pth_hello <thread_count>
 *
 * IPP:   Section 4.2 (p. 153 and ff.)
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 900000000
double sum;
/* Global variable:  accessible to all threads */
int thread_count;  

void *Hello(void* rank);  /* Thread function */
int flag = 0;
/*--------------------------------------------------------------------*/
int main() {
        long       thread;  /* Use long in case of a 64-bit system */
        pthread_t* thread_handles; 
        double step;

        /* Get number of threads from command line */
        thread_count = 4; 

        thread_handles = malloc (thread_count*sizeof(pthread_t)); 

        for (thread = 0; thread < thread_count; thread++)  
                pthread_create(&thread_handles[thread], NULL, Hello, (void*) thread);  

        for (thread = 0; thread < thread_count; thread++) 
                pthread_join(thread_handles[thread], NULL);
        free(thread_handles);
        step = 1.0/(double)N;
        sum = step*sum;
        printf("Pi = %lf\n", sum);
        return 0;
}  /* main */

/*-------------------------------------------------------------------*/
void *Hello(void* rank) {
        long my_rank = (long) rank;  /* Use long in case of 64-bit system */ 

        int i;
        double x, pi, tmp_sum = 0.0, step;
        int start, end, work_per_thd;
        step = 1.0/(double)N;
        work_per_thd = N/thread_count;
        start = my_rank * work_per_thd;
        end = start + work_per_thd;
        
        for(i=start; i<end; i++){
                x = (i)*1.0/(double)N;
                sum = sum + 4.0/(1.0+x*x);
        }
        tmp_sum = step * tmp_sum;
        while(flag != my_rank);
        sum += tmp_sum;
        flag++;        
        return 0;
}