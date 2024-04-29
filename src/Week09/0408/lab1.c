#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *A, int p, int q, int r, int *tmp) {
	int i,j,t;

	i = p;
	j = q+1;
	t = p;
	while(1) {
		if(i>q || j>r)
			break;

		if(A[i] < A[j]) {
			tmp[t] = A[i];
			i++;
		}
		else 
		{
			tmp[t] = A[j];
			j++;
		} 
		t++;
	}

	if(i>q) {  //왼쪽 부분배열을 모두 소비
		//오른쪽 부분배열의 남은 원소를 복사
		for( ; j<=r; j++, t++)
			tmp[t] = A[j];
	}
	else{
		for( ; i<=q; i++, t++)
			tmp[t] = A[i];
	}

	for(i=p; i<=r; i++)
		A[i] = tmp[i];
}

void merge_sort(int *A, int p, int r, int *tmp) {
	if(p<r) {
		int q = (p+r)/2;
		merge_sort(A, p, q, tmp);
		merge_sort(A, q+1, r, tmp);
		merge(A, p, q, r, tmp);
	}
}

int main() {
	int *arr, *tmp; 
	int n,i;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	tmp = (int*)malloc(sizeof(int)*n);

	srand(time(NULL));
	for(i=0; i<n; i++) 
		arr[i] = rand()%1000;

	for(i=0; i<n; i++) 
		printf("%d ", arr[i]);
	printf("\n");

	//insertion_sort(arr, n);
	merge_sort(arr, 0, n-1, tmp);

	for(i=0; i<n; i++) 
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);
	free(tmp);
	return 0;
}
