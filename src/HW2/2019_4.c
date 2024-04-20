#include <stdio.h>
#include <stdlib.h>

int pick(char item[], int n, int bucket[], int m, int toPick, int target);

int main() {
	char sign[] = { '+', '-'};
	int n = 2;
	int m, i;
	int *bucket;
	int count = 0;

	scanf("%d", &m);

	bucket = (int*) malloc(sizeof(int)*m);
	for(i=1; i<=m ;i++) {
		count = count + pick(sign, n, bucket, i, i, m);
	}
	printf("%d\n", count);
	free(bucket);
	return 0;
}

int pick(char item[], int n, int bucket[], int m, int toPick, int target) {
	int i, lastIndex, count;
	if(toPick == 0) {
		int sum = 0;
		for(i=0; i<m; i++) {
			//printf("%c%d ", item[bucket[i]], i+1);

			if(item[bucket[i]] == '+')
				sum = sum + (i+1);
			else if(item[bucket[i]] == '-')
				sum = sum - (i+1);
		}
		//printf("=%d\n", sum);
		if(sum == target) {
			for(i=0; i<m; i++) {
				printf("%c%d ", item[bucket[i]], i+1);
			}
			printf("=%d\n", sum);
			return 1;
		}
		return 0;	
	}

	lastIndex = m - toPick - 1;

	count = 0;
	for(i=0; i<n ; i++) {
		bucket[lastIndex+1] = i;
		count = count + pick(item, n, bucket, m, toPick-1, target);
	}

	return count;
}





