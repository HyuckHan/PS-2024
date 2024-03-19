#include <stdio.h>

int check_all_ones(int);

int main() {
	int n, i;

	n = 3;
	i = 1;

	while(1) {
		int multiple;
		int all_ones;

		multiple = n * i;
		i++;

		all_ones = check_all_ones(multiple);
		if(all_ones == 1) {
			printf( "%d\n", multiple);
			return 0;
		}
	}

	return 0;
}

int check_all_ones(int n) {
	
	while( n != 0 ) {
		int remainder_n;

		remainder_n = n % 10;
		n = n / 10;

		if( remainder_n != 1 ) 
			return 0;
	}

	return 1;
}
