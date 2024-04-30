#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *A, int p, int q, int r, int* temp) {
	int i,j,t;

	i = p;
	j = q+1;
	t = p;

	while(1) {
		if(i>q || j>r)
			break;
		
		if(A[i] < A[j]) {
			temp[t] = A[i];
			i++;
		}
		else {
			temp[t] = A[j];
			j++;
		}
		t++;
	}

	if(i>q) { //왼쪽 subarray의 처리가 끝.
		//오른쪽 subarray 잔여 아이템을 복사
		for( ; j<=r ; j++, t++)
			temp[t] = A[j];
	}
	else {
		for( ; i<=q ; i++, t++)
			temp[t] = A[i];
	}

	for(i=p; i<=r; i++)
		A[i] = temp[i];
}

void merge_sort(int *A, int p, int r, int *temp) {
	if(p<r) {
		int q = (p+r)/2;
		merge_sort(A, p, q, temp);
		merge_sort(A, q+1, r, temp);
		merge(A, p, q, r, temp);
	}
}

int main() {
	int *arr, *temp;
	int n,i;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	temp = (int*)malloc(sizeof(int)*n);

	srand(time(NULL));
	for(i=0; i<n; i++) 
		arr[i] = rand()%1000;

	for(i=0; i<n; i++) 
		printf("%d ", arr[i]);
	printf("\n");

	//insertion_sort(arr, n);
	merge_sort(arr, 0, n-1, temp);

	for(i=0; i<n; i++) 
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);
	free(temp);
	return 0;
}
