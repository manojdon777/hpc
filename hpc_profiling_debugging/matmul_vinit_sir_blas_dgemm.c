#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef INTEL
#include "mkl.h"
#else
#include <cblas.h>
#endif

#define N 3000

void create_square_matrix(double **MAT) {
#ifdef INTEL
	(*MAT) = (double *) mkl_malloc (sizeof(double) * N * N, 64);
	if ((*MAT) == NULL) { printf("Memory Error.\n"); exit(1);}
#else
	(*MAT) = (double *) malloc (sizeof(double) * N * N);
	if ((*MAT) == NULL) { printf("Memory Error.\n"); exit(1);}
#endif
}

void free_mat(double **MAT) {
#ifdef INTEL
	mkl_free((*MAT));
	(*MAT) = NULL;
#else
	free((*MAT));
	(*MAT) = NULL;
#endif
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

void mat_mul_cblas(double *A, double *B, double *C) {
	CBLAS_LAYOUT    l = CblasRowMajor;
	CBLAS_TRANSPOSE t = CblasNoTrans; 

	/*
	void cblas_dgemm(CBLAS_LAYOUT layout, CBLAS_TRANSPOSE TransA,
                 CBLAS_TRANSPOSE TransB, const CBLAS_INT M, const CBLAS_INT N,
                 const CBLAS_INT K, const double alpha, const double *A,
                 const CBLAS_INT lda, const double *B, const CBLAS_INT ldb,
                 const double beta, double *C, const CBLAS_INT ldc);
	*/

	cblas_dgemm(l, t, t, N, N, N, 1.0, A, N, B, N, 0.0, C, N);
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
	//printf("Creation & Initialization time = %f.\n", diff_time(T1, T2));

	T1 = clock();
	mat_mul(A, B, C);
	T2 = clock();
	printf("Matrix Multiplication time = %f.\n", diff_time(T1, T2));
	//print_mat(C);

	T1 = clock();
	mat_mul_cblas(A, B, C);	
	T2 = clock();
	printf("Matrix Multiplication time (CBLAS) = %f.\n", diff_time(T1, T2));
	//print_mat(C);

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
