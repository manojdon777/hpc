#include <omp.h>

int main() {
    int num_threads = 4;
    int thread_id;
    int cubes[num_threads];

     Parallel region starts
     #pragma omp parallel num_threads(num_threads)
      {    // Get the thread ID
            thread_id = omp_get_thread_num()

            // Calculate the cube of the 
             cubes[thread_id] = thread_id * thread_id * thread_id
             // Synchronize all threads
              #pragma omp barrier
    
             // Print the cube calculated by each thread
               #pragma omp critical
                 {
                   printf("Thread %d: Cube = %d\n", thread_id, cubes[thread_id]);
                  }
         }
           // Parallel region ends
   
                                                                                                                                                                                         return 0;                                                                                                                                                                                           }
