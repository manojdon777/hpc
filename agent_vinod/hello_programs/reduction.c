#include<stdio.h>
#include<omp.h>
#define NUM 100

int isprime( int x ){
	for (int y=2; y*y<=x; y++){
		if(x%y == 0)
			return 0;

	}
	printf("Number is %d: \n", x);
	return 1;
}

int main(){

	int sum=0;
	#pragma omp parallel for   //reduction (+:sum) 
	for(int i = 2; i<=NUM; i++){
		sum += isprime(i);
	}
	printf("Number of prime numbers: %d\n", sum);
	return 0;
}
