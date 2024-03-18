#include <stdio.h>

int main() {
	int n1, n2, carry_count, carry;

	n1 = 123;
	n2 = 999;
	carry_count = 0;
	carry = 0;

	//while( !(n1==0 && n2==0) )
	while( n1 != 0 || n2 != 0 ) {
		int remainder_n1;
		int remainder_n2;
		int sum;

		remainder_n1 = n1 % 10;
		remainder_n2 = n2 % 10;

		sum = remainder_n1 + remainder_n2 + carry;

		if( sum >= 10 ){
			carry_count++;
			carry = 1;
		} else {
			carry = 0;
		}
		
		n1 = n1 / 10;
		n2 = n2 / 10;
	}

	printf("%d\n", carry_count);

	return 0;
}
