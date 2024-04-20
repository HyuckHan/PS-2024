#include <stdio.h>
#include <stdlib.h>

int pick(char item[], int n, int bucket[], int m, int toPick, int *money);

int main() {
	char sign[] = { '+', '-', '0'};
	int *money;
	int n, i;
	int *bucket;

	scanf("%d", &n);

	money = (int*) malloc(sizeof(int)*n);
	bucket = (int*) malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		scanf("%d", &money[i]);

	printf("%d\n", pick(sign, 3, bucket, n, n, money));

	free(bucket);
	return 0;
}

int pick(char item[], int n, int bucket[], int m, int toPick, int *money) {
	int i, lastIndex, count;
	if(toPick == 0) {
		int sum = 0;
		/*for(i=0; i<m; i++) {
			printf("%c ", item[bucket[i]]);
		}
		printf("\n");*/

		for(i=0; i<m; i++) {
			if(item[bucket[i]] == '+')
				sum = sum + money[i];
			else if(item[bucket[i]] == '-')
				sum = sum - money[i];
		}
		
		if(sum == 0) {
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
		count = count + pick(item, n, bucket, m, toPick-1, money);
	}

	return count;
}
