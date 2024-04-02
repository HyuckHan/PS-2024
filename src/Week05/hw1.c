#include <stdio.h>
#include <stdlib.h>

void pick(int n, int bucket[], int m, int toPick);

int main() { 
	int n = 4;
	int m;
	int *bucket;

	scanf("%d", &m);

	bucket = (int*) malloc(sizeof(int)*m);
	pick(n, bucket, m, m);
	free(bucket);
	return 0;
}

void pick(int n, int bucket[], int m, int toPick) {
	int i, lastIndex;
	if(toPick == 0) {
		for(i=0; i<m; i++)
			printf("%d", bucket[i]);
		printf("\n");
		return;	
	}

	lastIndex = m - toPick - 1;

	for(i=0; i<n ; i++) {
		bucket[lastIndex+1] = i;
		pick(n, bucket, m, toPick-1);
	}
}
