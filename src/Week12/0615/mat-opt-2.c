#include <stdio.h>
#include <stdlib.h>

int mat_opt1(int **matrix, int i, int j, int **M, int **M2) {
	if(i==0 && j==0)
		return matrix[0][0];
	else if(i==0){
		if(M2[i][j-1] == 0) {
			M[i][j-1] = mat_opt1(matrix, i, j-1, M, M2);
			M2[i][j-1] = 1;
		}
		return M[i][j-1]+ matrix[i][j];
	}
	else if(j==0){
		if(M2[i-1][j] == 0) {
			M[i-1][j] = mat_opt1(matrix, i-1, j, M, M2);
			M2[i-1][j] = 1;
		}
		return M[i-1][j] + matrix[i][j];
	}
	else {
		if(M2[i][j-1] == 0) {
			M[i][j-1] = mat_opt1(matrix, i, j-1, M, M2);
			M2[i][j-1] = 1;
		}

		if(M2[i-1][j] == 0) {
			M[i-1][j] = mat_opt1(matrix, i-1, j, M, M2);
			M2[i-1][j] = 1;
		}

		return ((M[i][j-1]<M[i-1][j])?M[i][j-1]:M[i-1][j]) + matrix[i][j];
	}
}

int mat_opt2(int **matrix, int i, int j, int **M, int **M2) {
	if(M2[i][j] != 0)
		return M[i][j];

    if(i==0 && j==0)
        return matrix[0][0];
    else if(i==0) {
        M[i][j] = mat_opt2(matrix, i, j-1, M, M2) + matrix[i][j];
		M2[i][j] = 1;
		return M[i][j];
	}
    else if(j==0) {
        M[i][j] = mat_opt2(matrix, i-1, j, M, M2) + matrix[i][j];
		M2[i][j] = 1;
		return M[i][j];
	}
    else {
        int a, b;
        a = mat_opt2(matrix, i, j-1, M, M2);
        b = mat_opt2(matrix, i-1, j, M, M2);
        M[i][j] = ((a<b)?a:b) + matrix[i][j];
		M2[i][j] = 1;
		return M[i][j];
	}
}


int main() {
	int **m, **M, **M2, i, j;
	int r, c;
	r = 4; c = 4;

	m = (int**)malloc(sizeof(int*)*r);
	M = (int**)malloc(sizeof(int*)*r);
	M2 = (int**)malloc(sizeof(int*)*r);
	for(i=0 ;i<r; i++){
		m[i] = (int*)malloc(sizeof(int)*c);
		M[i] = (int*)malloc(sizeof(int)*c);
		M2[i] = (int*)malloc(sizeof(int)*c);
	}

	for(i=0 ;i<r; i++)
		for(j=0 ;j<r; j++){
			scanf("%d", &m[i][j]);
			M2[i][j] = 0;
		}

	printf("%d\n", mat_opt1(m, r-1, c-1, M, M2));
	return 0;
}
