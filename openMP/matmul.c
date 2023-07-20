#include<stdio.h>
#define N 8
int main(){
        int a[N][N], b[N][N], c[N][N];
        int temp;

        // #pragma omp parallel for shared(c) private(a,b)
        for (int i = 0; i < N; ++i)
        {
                #pragma omp parallel for
                for (int j = 0; j < N; ++j)
                {
                        a[i][j] = 1;
                        b[i][j] = 2;
                        c[i][j] = 0;
                }
        }

        // #pragma omp parallel for shared(c) private(a,b)
        for (int i = 0; i < N; ++i)
        {
                #pragma omp parallel for
                for (int j = 0; j < N; ++j)
                {       

                        #pragma omp parallel for
                        for (int k = 0; k < N; ++k)
                        {
                                c[i][j] += a[i][k] * b[k][j];
                        }
                }
        }

        for (int i = 0; i < N; ++i)
                {
                        for (int j = 0; j < N; ++j)
                        {
                                printf("%d ",c[i][j]);
                        }
                        printf("\n");
                }
        return 0;
}