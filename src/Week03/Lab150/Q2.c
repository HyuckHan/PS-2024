#include <stdio.h>

int calculrate_reverse(int n);

int main() {
	int n = 196;
	int n_reverse;
	int operation_count = 0;

	n_reverse = calculrate_reverse(n);

	while( n != n_reverse ){
		operation_count = operation_count + 1;
		n = n + n_reverse;

		if( n <= 0 ) {
			printf("Overflow\n");
			return 0;
		}

		n_reverse = calculrate_reverse(n);
	}

	printf("%d %d\n", operation_count, n);

	return 0;
}

int calculrate_reverse(int n) {
	int ret = 0;
	
	while(n!=0) {
		int remainder_n;

		remainder_n = n%10;
		n = n / 10;

		ret = ret * 10;
		ret = ret + remainder_n;
	}

	return ret;
}
