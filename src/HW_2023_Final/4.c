#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UPPERCASE	0
#define LOWERCASE	1
#define NUMERICCASE	2

int type_char(char ch) {
	if(ch >= 'A' && ch <= 'Z')
		return UPPERCASE;
	else if(ch >= 'a' && ch <= 'z')
		return LOWERCASE;
	else if(ch >= '0' && ch <= '9')
		return NUMERICCASE;
	return -1; //error
}

int compare(char a, char b) {
	//if a < b -> 1
	//else 0
	int a_type, b_type;

	a_type = type_char(a);
	b_type = type_char(b);

	if(a_type == b_type) {
		if(a < b)
			return 1;
		else 
			return 0;
	}
	else{
		if(a_type < b_type)
			return 1;
		else 
			return 0;
	}
}

int partition(char *A, int p, int r) {
	int i, j;
	//int pivot;
	char pivot;
	int t;

	i = p - 1;
	j = p;

	pivot = A[r];

	for(j=p; j<r; j++) {
		//if(A[j] < pivot) {
		if(compare(A[j], pivot) == 1) {
			i++;
			t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
	}
	i++;
	t = A[i];
	A[i] = A[r];
	A[r] = t;

	return i;
}

void quick_sort(char *A, int p, int r) {
	if(p<r) {
		int q = partition(A, p, r);
		quick_sort(A, p, q-1);
		quick_sort(A, q+1, r);
	}
}

int main() {
	int len, i;
	int MAX_LEN = 500000;
	char *str_to_sort;

	str_to_sort = (char*) malloc(sizeof(char)*MAX_LEN);
	for(i=0; i<MAX_LEN; i++)
		str_to_sort[i] = '\0';

	scanf("%s", str_to_sort);

	len = strlen(str_to_sort);

	quick_sort(str_to_sort, 0, len-1);

	printf("%s\n", str_to_sort);

	free(str_to_sort);
	return 0;
}
