#include<stdio.h>

int check_all_ones(int);

int main() {
	int n = 3;
	int i;
	int has_all_ones = 0; 
	int multiple;

	i = 1;
	while( has_all_ones == 0 ) {

		multiple = n * i;
		
		has_all_ones = check_all_ones(multiple);

		i++;
	}

	printf( "%d\n", multiple);

	return 0;
}

int check_all_ones(int n) {

	while( n != 0 ){
		int remainder_n;

		remainder_n = n % 10;
		n = n / 10;

		if( remainder_n != 1 )
			return 0;

	}

	return 1;
}
