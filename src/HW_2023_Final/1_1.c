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

int main() {
	int M, N, i, j, count;
	int *items_for_sale, *items_for_purchase;

	scanf("%d", &M);
	items_for_sale = (int*)malloc(sizeof(int)*M);
	for(i=0; i<M; i++)
		scanf("%d", &items_for_sale[i]);

	scanf("%d", &N);
	items_for_purchase = (int*)malloc(sizeof(int)*N);
	for(i=0; i<N; i++) 
		scanf("%d", &items_for_purchase[i]);

	quick_sort(items_for_sale, 0, M-1);
	quick_sort(items_for_purchase, 0, N-1);

	count = 0;
	i=0; j=0;

	while(1) {
		if(items_for_sale[i] == items_for_purchase[j]) {
			count++;
			j++;
		}
		else if(items_for_sale[i] < items_for_purchase[j]) {
			i++;
		}
		else {
			j++;
		}
		if(j == N)
			break;
	}

	printf("%d\n", count);

	free(items_for_sale);
	free(items_for_purchase);
	return 0;
}
