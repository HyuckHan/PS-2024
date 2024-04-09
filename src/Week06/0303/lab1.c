#include <stdio.h>

int right_max_sum(int A[], int left, int right) {
	int i, max, sum;
	max = A[left];
	sum = A[left];
	for(i=left+1; i<=right; i++) {
		sum = sum + A[i];
		if(max < sum)
			max = sum;
	}
	return max;
}

int main() {
	int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

	int max = right_max_sum(A, 3, 5);
	printf("max value = %d\n", max);

	max = right_max_sum(A, 3, 4); 
	printf("max value = %d\n", max);

	max = right_max_sum(A, 5, 7);
	printf("max value = %d\n", max);
	return 0;
}
