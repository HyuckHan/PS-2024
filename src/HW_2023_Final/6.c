#include<stdio.h>
#include<string.h>

void pick(int *items, int n, int *bucket, int m, int toPick, char *num_str_1, char *num_str_2, int *max) {
	int i, lastIndex, smallest, j, flag, num1, num2;

	if(toPick==0) {
		for(i=0; i<m; i++)
			printf("%d ", items[bucket[i]]);
	
		num1 = 0;
		for(i=0; i<strlen(num_str_1); i++)
			num1 = num1*10 + items[bucket[num_str_1[i]-'A']];
		num2 = 0;
		for(i=0; i<strlen(num_str_2); i++)
			num2 = num2*10 + items[bucket[num_str_2[i]-'A']];

		printf("(");
		for(i=0; i<strlen(num_str_1); i++)
			printf("%d", items[bucket[num_str_1[i]-'A']]);
		printf(")(");
		for(i=0; i<strlen(num_str_2); i++)
			printf("%d", items[bucket[num_str_2[i]-'A']]);
		printf(")");

		printf("(%d)", (num1));
		printf("(%d)", (num2));
		if(*max<(num1+num2)) {
			*max=(num1+num2);
		}
		printf("\n");
		return;
	}

	lastIndex = m - toPick -1;

	for(i=0; i<n; i++) {
		flag = 0;
		for(j=0; j<=lastIndex; j++){
			if(bucket[j] == i)
				flag = 1;
		}
		if(flag==1) continue;

		bucket[lastIndex+1] = i;
		pick(items, n, bucket, m, toPick-1, num_str_1, num_str_2, max);
	}
}

int main() {
	char num_str_1[8] = {0};
	char num_str_2[8] = {0};
	int max = 0;

	int items[5] = {1,2,3,4,5};
	int bucket[5];

	scanf("%s", num_str_1);
	scanf("%s", num_str_2);

	pick(items, 5, bucket, 5, 5, num_str_1, num_str_2, &max);
	printf("%d\n", max);
	return 0;
}
