#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cblas.h>

#define N 3000

void create_square_matrix(double **MAT) {
	(*MAT) = (double *) malloc (sizeof(double) * N * N);
	if ((*MAT) == NULL) { printf("Memory Error.\n"); exit(1);}
}

void free_mat(double **MAT) {
	free((*MAT));
	(*MAT) = NULL;
}

void init_mat(double *MAT) {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			MAT[i * N + j] = (rand() % 100) / 100.0;
}

void print_mat(double *MAT) {
	printf("----------------------------------\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%5.2f", MAT[i * N + j]);
		}
		printf("\n");
	}
	printf("----------------------------------\n");
}

void mat_mul(double *A, double *B, double *C) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			double res = 0.0;
			for (int k = 0; k < N; ++k) {
				//printf("Mul: %f x %f.\n", A[i * N + k], B[k * N + j]);
				res += A[i * N + k] * B[k * N + j];
			}
			C[i * N + j] = res;
		}
	}
}

double diff_time(clock_t t1, clock_t t2) {
	return (t2 - t1) / (double) CLOCKS_PER_SEC;
}

int main (int argc, char *argv[]) {

	double* A;
	double* B;
	double* C;
	
	clock_t T1, T2;

	T1 = clock();
	create_square_matrix(&A);
	create_square_matrix(&B);
	create_square_matrix(&C);

	init_mat(A);
	init_mat(B);
	T2 = clock();
	// printf("Creation & Initialization time = %f.\n", diff_time(T1, T2));

	T1 = clock();
	cblas_dgemm('N', 'N', 'N', N, N, N, 1.0, A, N, B, N, 0.0, C, N);
	T2 = clock();
	printf("Matrix Multiplication time = %f.\n", diff_time(T1, T2));

	/*print_mat(A);
	print_mat(B);
	print_mat(C);*/

	double sum = 0.0;
	for (int i = 0; i < N * N; ++i) sum += C[i];
	
	printf("SUM = %f\n", sum); 

	free_mat(&A);
	free_mat(&B);
	free_mat(&C);
	
	return 0;
}
