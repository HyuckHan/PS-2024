#include<stdio.h>
#include<string.h>

void reverse_string(char *src, char *dest, int len) {
	int i=0;

	for(i=0; i<len; i++)
		dest[i] = src[len-i-1];
}

int main() {
	char str_number1[101] = {0};
	char str_number2[101] = {0};
	char str_number1_reverse[101] = {0};
	char str_number2_reverse[101] = {0};
	int len1, len2, max_len, i;
	int carry = 0;
	int carry_counter = 0;

	scanf("%s", str_number1);
	scanf("%s", str_number2);

	len1 = strlen(str_number1);
	len2 = strlen(str_number2);

	reverse_string(str_number1, str_number1_reverse, len1);
	reverse_string(str_number2, str_number2_reverse, len2);

	max_len = len1>len2 ? len1 : len2;

	for(i=0; i<max_len; i++) {
		int current_digit1;
		int current_digit2;

		current_digit1 = (str_number1_reverse[i]==0) ? 0 : str_number1_reverse[i]-'0';
		current_digit2 = (str_number2_reverse[i]==0) ? 0 : str_number2_reverse[i]-'0';

		if( (carry+current_digit1+current_digit2) > 9 ) {
			carry_counter++;
			carry=1;
		}
		else 
			carry=0;
	}

	printf("%d", carry_counter);
	return 0;
}
