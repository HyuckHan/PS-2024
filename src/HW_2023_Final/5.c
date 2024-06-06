#include <stdio.h>
#include <stdlib.h>

void pick(int *items, int n, int *bucket, int m, int toPick, int even_number, int *count, int L) {
	int i, lastIndex, smallest, currentItem;

	if(toPick + even_number < L)
		return;

	if(toPick==0) {
		//count[0] = count[0] + 1;
		*count = *count + 1;
		return;
	}

	lastIndex = m - toPick - 1;
	if(m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;
	
	for(i=smallest; i<n; i++) {
		bucket[lastIndex+1] = i;
		currentItem = items[i];
		if(currentItem%2 == 0)
			pick(items, n, bucket, m, toPick-1, even_number+1, count, L);
		else
			pick(items, n, bucket, m, toPick-1, even_number, count, L);
	}
}

int main() {
	int N, M, L, i;
	int *bucket, *items;
	int count = 0;

	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &L);

	items = (int*) malloc(sizeof(int)*N);
	bucket = (int*) malloc(sizeof(int)*M);

	for(i=0; i<N; i++)
		items[i] = i+1;
	
	pick(items, N, bucket, M, M, 0, &count, L);
	printf("%d\n", count);
	
	free(bucket);
	free(items);
	return 0;
}
