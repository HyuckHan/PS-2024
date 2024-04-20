#include <stdio.h>
#include <stdlib.h>

int pick(int item[], int n, int bucket[], int m, int toPick, int sum);

int main() {
	int *card;
	int n, i, sum;
	int *bucket;

	scanf("%d", &n);

	card = (int*) malloc(sizeof(int)*n);
	bucket = (int*) malloc(sizeof(int)*(n-1));
	sum = 0;
	for(i=0; i<n; i++) {
		scanf("%d", &card[i]);
		sum = sum + card[i];
	}

	printf("%d\n", pick(card, n, bucket, n-1, n-1, sum));

	free(bucket);
	return 0;
}

int pick(int item[], int n, int bucket[], int m, int toPick, int sum) {
	int i, lastIndex, count, flag, j;
	if(toPick == 0) {
		int number = 0;
		int chosen_sum = 0;
		int remaining_num;
		for(i=0; i<m; i++) {
			printf("%d ", item[bucket[i]]);
			chosen_sum = chosen_sum + item[bucket[i]];
		}
		remaining_num = sum - chosen_sum;
		for(i=0; i<m; i++) 
			number = number * 10 + item[bucket[i]];
		printf(" -> %d %d\n", number, remaining_num);

		if(number % remaining_num == 0) {
			return 1;
		}
		return 0;
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
		count = count + pick(item, n, bucket, m, toPick-1, sum);
	}
	return count;
}
