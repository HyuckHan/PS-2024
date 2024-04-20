#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *A, int n, int order) {
    int i,j;
    int  tmp;

    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            if(order == 1 && A[j]>A[j+1]) {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }

			if(order == 0 && A[j]<A[j+1]) {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }

        }
    }
}

int main() {
	int *A, *B;
	int N, K, i, sum;

	scanf("%d", &N); 
	scanf("%d", &K); 

	A = (int*)malloc(sizeof(int)*N);
	B = (int*)malloc(sizeof(int)*N);

	for(i=0; i<N; i++)
		scanf("%d", &A[i]);
	for(i=0; i<N; i++)
		scanf("%d", &B[i]);

	
	bubble_sort(A, N, 0); //A를 내림차순으로
	bubble_sort(B, N, 1); //B를 오름차순으로

	for(i=0; i<N; i++)
		printf("%d ", A[i]);
	printf("\n");

	for(i=0; i<N; i++)
		printf("%d ", B[i]);
	printf("\n");


	for(i=0; i<K; i++)
		B[i] = A[i];
	
	sum = 0;
	for(i=0; i<N; i++) {
		sum = sum + B[i];
		printf("%d ", B[i]);
	}
	printf("\n%d\n", sum);


	return 0;
}
