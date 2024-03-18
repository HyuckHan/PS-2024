#include<stdio.h>

int make_number_ones(int);

int main() {
	int n = 3;
	int i;
	int multiple_ones;

	i=0;
	while(1) {
		i++;
		multiple_ones = make_number_ones(i);
		
		if( multiple_ones % n == 0 ) {
			printf("%d\n", i);
			return 0;
		}
	}
	//printf
	return 0;
}

int make_number_ones(int n) {
	int ret = 0;
	int i;

	for(i=0; i<n ; i++)
		ret = ret*10 + 1;

	return ret;
}
