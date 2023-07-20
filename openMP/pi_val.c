#include<stdio.h>
static long num_steps = 4;
double steps;
int main(){
        double pi, x, sum = 0.0;
        steps = 1.0/(double)num_steps;

        // #pragma omp parallel for firstprivate(steps, num_steps) shared(sum) private(x)
        for (int i = 0; i < num_steps; i++){
                x = (i + 0.5) * steps;
                sum += 4.0 / (1.0 + x * x);
        }
        pi = steps * sum;
        
        printf("%f", pi);
        return 0;
}