#include <stdio.h>
#include <stdlib.h>

void pick(int item[], int n, int bucket[], int m, int toPick, int target_money);

int main() {
	int money[] = {1000, 5000, 10000, 0};
	int target_money, m;
	int *bucket;

	scanf("%d", &target_money);
	m = target_money/1000;

	bucket = (int*) malloc(sizeof(int)*m);
	pick(money, 4, bucket, m, m, target_money);
	free(bucket);
	return 0;
}

void pick(int item[], int n, int bucket[], int m, int toPick, int target_money) {
	int i, lastIndex, smallest;
	if(toPick == 0) {
		int sum = 0;
		for(i=0; i<m; i++) 
			sum = sum + item[bucket[i]];

		if(sum == target_money) {
			for(i=0; i<m; i++) {
				if(item[bucket[i]] != 0)
					printf("%d ", item[bucket[i]]);
                		}
			printf("\n");
		}
		return;
	}

	lastIndex = m - toPick - 1;
	if(m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for(i=smallest; i<n ; i++) {
		bucket[lastIndex+1] = i;
		pick(item, n, bucket, m, toPick-1, target_money);
	}
}
