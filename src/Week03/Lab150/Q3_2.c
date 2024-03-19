#include <stdio.h>

int make_number(int n);

int main() {
	int n ;
	int i ;

	n = 3;
	i = 1;

	while(1) {
		int number_ones;

		number_ones = make_number(i);

		if( number_ones <= 0 ) {
			printf("Overflow\n");
			return 0;
		}

		if( number_ones % n == 0 ) {
			printf("%d\n", i);
			return 0;
		}
		i++;
	}
	return 0;
}

int make_number(int n) {
	int ret;
	int i;

	ret = 0;

	for(i=0; i<n ; i++)
		ret = ret * 10 + 1;

	return ret;
}
