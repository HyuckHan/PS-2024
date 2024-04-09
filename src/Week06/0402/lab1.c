#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

	free(arr);
	return 0;
}
