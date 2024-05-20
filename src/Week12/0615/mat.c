#include <stdio.h>
#include <stdlib.h>

int mat(int **matrix, int i, int j) {
	if(i==0 && j==0)
		return matrix[0][0];
	else if(i==0)
		return mat(matrix, i,j-1) + matrix[i][j];
	else if(j==0)
		return mat(matrix, i-1,j) + matrix[i][j];
	else {
		int a, b;
		a = mat(matrix, i,j-1);
		b = mat(matrix, i-1,j);

		return ((a<b)?a:b) + matrix[i][j];
	}
}

int main() {
	int **m, i, j;
	int r, c;
	r = 4; c = 4;

	m = (int**)malloc(sizeof(int*)*r);
	for(i=0 ;i<r; i++)
		m[i] = (int*)malloc(sizeof(int)*c);

	for(i=0 ;i<r; i++)
		for(j=0 ;j<r; j++)
			scanf("%d", &m[i][j]);

	printf("%d\n", mat(m, r-1, c-1));
	return 0;
}
