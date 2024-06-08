#include <stdio.h>
#include <stdlib.h>

void pick(int *items, int n, int *bucket, int m, int toPick, int target, int currentSum, int *min) {
	int i, smallest, lastIndex;

	if( (m-toPick) >= *min )
		return;

	if(target == currentSum) {
		for(i=0; i<m-toPick; i++)
			printf("%d ", items[bucket[i]]);
		printf("\n");
		if(*min>(m-toPick))
			*min = m - toPick;
		return;
	}

	if(target<currentSum)
		return;

	if(toPick == 0)
		return;
	

	lastIndex = m - toPick - 1;

	if(m==toPick)
		smallest = 0;
	else
		smallest = bucket[lastIndex];

	for(i=smallest; i<n ;i++) {
		bucket[lastIndex+1] = i;
		pick(items, n, bucket, m, toPick-1, target, currentSum + items[i], min);
	}
}

int main(void) {
        int i, n, size, min;
        int *item;
        int *bucket;

        scanf("%d", &n);

        for (size = 1; size*size<n; size++) {}
		size--;

		item = (int*) malloc(sizeof(int)*size);
		bucket = (int*) malloc(sizeof(int)*n);

        for (i=0; i<size; i++) 
			item[size-i-1] = (i+1)*(i+1);
			//item[i] = (i+1)*(i+1);
		
        for (i=0; i<size; i++) 
			printf("%d ", item[i]);
		printf("\n");

		min = n;
		pick(item, size, bucket, n, n, n, 0, &min);

        printf("%d\n", min);

		free(item);
		free(bucket);
        return 0;
}
