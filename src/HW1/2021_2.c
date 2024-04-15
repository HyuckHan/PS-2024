#include<stdio.h>
#include<string.h>

int get_reverse_number(int n, int *arr) {
    int count = 0;
    int number, i;

    number = n;
    while(number!=0) {
        count= count + 1;
        number = number/10;
    }

    number = n;
    i = count;
    while(number!=0) {
        i--;
        arr[i] = number%10;
        number = number/10;
    }
    return count;
}

int main() {
	int N, i;
	int reverse_number[10] = {0};
	int digits;

	i = 0;

	scanf("%d", &N);

	N = N * 9; 
	digits = get_reverse_number(N, reverse_number);
	for(i=0; i<digits; i++) 
		printf("%d ", reverse_number[i]);

	return 0;
}
