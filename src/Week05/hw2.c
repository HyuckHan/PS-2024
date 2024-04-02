#include <stdio.h>
#include <stdlib.h>

void pick(char item[], int n, int bucket[], int m, int toPick);

int main() {
	char sign[] = { '+', '-'};
	int n = 2;
	int m;
	int *bucket;

	scanf("%d", &m);

	bucket = (int*) malloc(sizeof(int)*m);
	pick(sign, n, bucket, m, m);
	free(bucket);
	return 0;
}

void pick(char item[], int n, int bucket[], int m, int toPick) {
	int i, lastIndex;
	if(toPick == 0) {
		int sum = 0;
		for(i=0; i<m; i++) {
			printf("%c%d ", item[bucket[i]], i+1);

			if(item[bucket[i]] == '+')
				sum = sum + (i+1);
			else if(item[bucket[i]] == '-')
				sum = sum - (i+1);
		}
		printf("=%d\n", sum);
		return;	
	}

	lastIndex = m - toPick - 1;

	for(i=0; i<n ; i++) {
		bucket[lastIndex+1] = i;
		pick(item, n, bucket, m, toPick-1);
	}
}





