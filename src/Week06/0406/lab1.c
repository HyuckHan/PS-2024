#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertion_sort(int *A, int n) {
	int i, j, k, temp;

	for(i=1; i<n; i++) {
		for(j=0; j<i; j++)
			if(A[i] < A[j]) 
				break;

		temp = A[i];

		for(k=i; k>j; k--) 
			A[k] = A[k-1];

		A[j] = temp;
	}
}

int main() {
	int *arr; 
	int n,i;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);

	srand(time(NULL));
	for(i=0; i<n; i++) 
		arr[i] = rand()%1000;

	for(i=0; i<n; i++) 
		printf("%d ", arr[i]);
	printf("\n");

	insertion_sort(arr, n);

	for(i=0; i<n; i++) 
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);
	return 0;
}
