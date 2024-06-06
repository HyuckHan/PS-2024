#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int p, int r) {
	int i, j;
	int pivot;
	int t;

	i = p - 1;
	j = p;

	//t = <- random int from (p,r)
	//swap A[t] <--> A[r]
	pivot = A[r];

	for(j=p; j<r; j++) {
		if(A[j] < pivot) {
			i++;
			//swap A[i] <--> A[j]
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	i++;
	//swap A[i] <--> A[r]
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

int binary_search(int *A, int p, int r, int target) {
	int m;

	m = (p+r)/2;

	if(p>r)
		return -1;

	if(A[m] == target) 
		return m;
	else if(A[m] < target)
		return binary_search(A, m+1, r, target);
	else
		return binary_search(A, p, m-1, target);
}

int main() {
	int M, N, i, count;
	int *items_for_sale, *items_for_purchase;

	scanf("%d", &M);
	items_for_sale = (int*)malloc(sizeof(int)*M);
	for(i=0; i<M; i++)
		scanf("%d", &items_for_sale[i]);

	quick_sort(items_for_sale, 0, M-1);

	scanf("%d", &N);
	items_for_purchase = (int*)malloc(sizeof(int)*N);
	count = 0;
	for(i=0; i<N; i++) {
		scanf("%d", &items_for_purchase[i]);
		if(binary_search(items_for_sale, 0, M-1, items_for_purchase[i]) != -1)
			count++;
	}

	printf("%d\n", count);

	free(items_for_sale);
	free(items_for_purchase);
	return 0;
}
