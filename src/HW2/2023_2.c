#include <stdio.h>
#include <stdlib.h>

int pick(int item[], int n, int bucket[], int m, int toPick, int *A, int *B, int *temp);

int main() {
	int *A, *B, *temp;
	int Na, Nb, i;
	int *bucket, *item;

	scanf("%d", &Na);
	A = (int*) malloc(sizeof(int)*Na);
	for(i=0; i<Na; i++) 
		scanf("%d", &A[i]);

	scanf("%d", &Nb);
	B = (int*) malloc(sizeof(int)*Nb);
	temp = (int*) malloc(sizeof(int)*Nb);
	for(i=0; i<Nb; i++) 
		scanf("%d", &B[i]);

	item = (int*) malloc(sizeof(int)*Nb);
	for(i=0; i<Nb; i++) 
		item[i] = i;

	bucket = (int*) malloc(sizeof(int)*Na);

	printf("%d\n", pick(item, Nb, bucket, Na, Na, A, B, temp));

	free(bucket);
	free(A);
	free(B);
	return 0;
}

int is_arithmetic_sequence(int arr[], int n) {
    if (n <= 2)
        return 1;

    // 등차 수열인지 확인
    int diff = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i-1] != diff)
            return 0;
    }
    return 1;
}
int pick(int item[], int n, int bucket[], int m, int toPick, int *A, int *B, int *temp) {
	int i, lastIndex, count, flag, j, sum;
	if(toPick == 0) { 
		for(i=0; i<m; i++)
			printf("%d ", item[bucket[i]]);
		printf(" --> ");

		for(i=0; i<n; i++)
			temp[i] = B[i];

		for(i=0; i<m; i++) {
			int target_idx = item[bucket[i]];
			temp[target_idx] = A[i];
		}

		for(i=0; i<n; i++)
			printf("%d ", temp[i]);
		printf("\n");

		if(is_arithmetic_sequence(temp,n)==1) {
			sum = 0;
			for(i=0; i<n; i++)
				sum = sum + temp[i];
			return sum;
		}

		return -1;
	}

	lastIndex = m - toPick - 1;

	count = 0;
	for(i=0; i<n ; i++) {
		flag = 0;
		for(j=0; j<=lastIndex ; j++) {
			if(bucket[j] == i) {
				flag = 1;
				break;
			}
		}
		if(flag==1)
			continue;

		bucket[lastIndex+1] = i;
		count = pick(item, n, bucket, m, toPick-1, A, B, temp);
		if(count != -1 )
			return count;
	}

	return -1;
}
