#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 3

void initialize_matrix(double **arr){
	arr = (double **)malloc(N * sizeof(double *));
	for(int i=0; i<N; i++)
		arr[i] = (double *)malloc(N * sizeof(double));
	srand(time(0));
	for(int i=0; i<N; i++){
		for(int j=0;j<N; j++){
			arr[i][j] = (double)(rand()%100)/100;
		}
	}
}

void print_matrix(double **arr){
	printf("-------------------------------------------------\n");
	for(int i=0; i<N; i++){
		for(int j=0;j<N; j++){
			printf("%lf\t\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------------------\n");
}

void multiply_matrix(double **a, double **b, double **c){

	c = (double **)malloc(N * sizeof(double *));
	for(int i=0; i<N; i++)
		c[i] = (double *)malloc(N * sizeof(double));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			double res = 0.0;
			for (int k = 0; k < N; ++k)
			{
				res += a[i][k] * b[k][j];
			}
			c[i][j] = res;
		}
	}
}

int main(){
	double **a, **b,**c;

	clock_t t1, t2;
	t1 = clock();
	initialize_matrix(a);
	initialize_matrix(b);
	t2 = clock();
	printf("Matrix creation time = %ld\n", t2 - t1);

	// // print_matrix(a);
	// // print_matrix(b);
	// t1 = clock();
	multiply_matrix(a, b, c);
	// t2 = clock();
	// printf("Matrix multiplication time = %ld\n", t2 - t1);
	// print_matrix(c);

	return 0;
}
