#include <stdio.h>

void pick(char item[], int n, int bucket[], int m, int toPick);

int main() {
	char item[] = { 'A', 'B', 'C' , 'D', 'E', 'F', 'G' };
	int bucket[3];

	pick(item, 7, bucket, 3, 3);

	return 0;
}

void pick(char item[], int n, int bucket[], int m, int toPick){
	int i, lastIndex, smallest;

	if(toPick == 0) {
		for(i=0; i<m; i++)
			//printf("%d ", bucket[i]);
			printf("%c ", item[bucket[i]]);
		printf("\n");
		return;

	}

	lastIndex = m - toPick - 1;

	if(m == toPick)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for(i=smallest; i<n ; i++) {
		bucket[lastIndex+1] = i;
		pick(item, n, bucket, m, toPick-1);
	}
}













