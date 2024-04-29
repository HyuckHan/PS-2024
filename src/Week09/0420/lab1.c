#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *A, int p, int r) {
	int i,j,t;
	int pivot;

	pivot = A[r];
	i = p-1;

	for(j=p; j<r; j++) {
		if(A[j] < pivot) {
			i++;
			//swap A[i] <-> A[j]
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}

	i++;
	//swap A[i] <-> A[r]
	t = A[i];
	A[i] = A[r];
	A[r] = t;

	return i;
}

void quick_sort(int *A, int p, int r) {
	if(p<r) {
		int q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
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

	//insertion_sort(arr, n);
	quick_sort(arr, 0, n-1);

	for(i=0; i<n; i++) 
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);
	return 0;
}
