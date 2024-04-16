#include<stdio.h>
#include<string.h>

int main() {
	char ladder[100][100] = {0};
	int M, N, i, j, curr_pos;

	scanf("%d", &M);
	scanf("%d", &N);
	scanf("%d", &curr_pos);

	for(i=0; i<N; i++)
		scanf("%s", ladder[i]);

	for(i=0; i<N; i++) {
		if(curr_pos == 0) {
			if (ladder[i][curr_pos] == '1') 
				curr_pos++;
		}
		else if(curr_pos == (M-1)) {
			if(ladder[i][curr_pos-1] == '1')
				curr_pos--;
		}
		else {
			if(ladder[i][curr_pos] == '1') {
				curr_pos++;
			}
			else if(ladder[i][curr_pos-1] == '1') {
				curr_pos--;
			}
		}
	}
	
	printf("%d", curr_pos);

	return 0;
}
