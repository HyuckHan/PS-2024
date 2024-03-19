#include <stdio.h>

int get_reverse_number(int);

int main() {
	int n;
	int n_reverse;
	int step;
       
	n = 196;
	step = 0;

	n_reverse = get_reverse_number(n);
	//printf("%d\n", n_reverse );

	while( n != n_reverse ) {
		n = n + n_reverse;
		if( n <= 0 ) {
			printf("Overflow\n");
			return 0;
		}
		n_reverse = get_reverse_number(n);
		step++;
	}
	printf("%d %d\n", step, n );
	return 0;
}

int get_reverse_number(int n) {
	int ret;

	ret = 0;

	while( n != 0 ) {
		int remainder_n;

		remainder_n = n % 10;
		n = n / 10;

		ret = ret * 10 + remainder_n;
	}

	return ret;
}

