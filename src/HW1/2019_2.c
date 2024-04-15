#include<stdio.h>
#include<string.h>

int main() {
	char str_number[52] = {0};
	int last_digit=0;
	int last_two_digits=0;
	int len=0;
	int sum_of_digits=0;
	int mulitple_of_two=0;
	int mulitple_of_three=0;
	int mulitple_of_four=0;
	int mulitple_of_five=0;
	int i;

	scanf("%s", str_number);
	
	len = strlen(str_number);

	last_digit = str_number[len-1] - '0';

	for(i=0; i<len; i++)
		sum_of_digits = sum_of_digits + str_number[i] - '0';
	
	last_two_digits = (str_number[len-2]-'0')*10 + last_digit;

	if(last_digit%2 == 0)
		mulitple_of_two = 1;

	if(sum_of_digits%3 == 0)
		mulitple_of_three = 1;

	if(last_two_digits%4 == 0)
		mulitple_of_four = 1;

	if(last_digit%5 == 0)
		mulitple_of_five = 1;

	printf("%d%d%d%d", mulitple_of_two, mulitple_of_three, 
		mulitple_of_four, mulitple_of_five);
	return 0;
}
