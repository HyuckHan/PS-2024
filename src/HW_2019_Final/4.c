#include<stdio.h>
#include<stdlib.h>

void pick(int *items, int n, int *bucket, int m, int toPick, int sum, int *min) {
	int i, smallest, lastIndex, sum1, sum2, diff;

	if(toPick==0) {
		sum1 = 0;
		for(i=0; i<m; i++) {
			printf("%d ", items[bucket[i]]);
			sum1 = sum1 + items[bucket[i]];
		}

		sum2 = sum - sum1;
		if(sum1>sum2)
			diff = sum1 - sum2;
		else
			diff = sum2 - sum1;

		printf("(%d)(%d)(%d)\n", sum1, sum2, diff);

		if(*min>diff)
			*min=diff;
		return;
	}

	lastIndex = m - toPick - 1;
	if(m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for(i=smallest; i<n; i++) {
		bucket[lastIndex+1] = i;
		pick(items, n, bucket, m, toPick -1, sum, min);
	}
}

int main() {
	int n, i;
	int *cap;
	int *bucket;
	int sum, min;

	scanf("%d", &n);

	cap = (int*) malloc(sizeof(int)*n);
	bucket = (int*) malloc(sizeof(int)*(n/2));
	
	sum = 0;
	for(i=0; i<n; i++) {
		scanf("%d", &cap[i]);
		sum = sum + cap[i];
	}

	bucket[0] = 0;
	min = sum;
	pick(cap, n, bucket, n/2, n/2-1, sum, &min);

	printf("%d\n", min);

	free(cap);
	free(bucket);
	return 0;
}
