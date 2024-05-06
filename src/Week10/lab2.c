#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **a, int r, int c);
void printMatrix(int **a, int r, int c);
void matrixAdd(int **a, int **b, int **x, int r, int c);

int main() {
	int **a, **b, **x;
	int i,r,c;

	scanf("%d", &r);
	scanf("%d", &c);

	a = (int**) malloc(sizeof(int*)*r);
	b = (int**) malloc(sizeof(int*)*r);
	x = (int**) malloc(sizeof(int*)*r);

	for(i=0; i<r; i++) {
		a[i] = (int*) malloc(sizeof(int)*c);
		b[i] = (int*) malloc(sizeof(int)*c);
		x[i] = (int*) malloc(sizeof(int)*c);
	}

	readMatrix(a, r, c);
	readMatrix(b, r, c);
	matrixAdd(a, b, x, r, c);
	printMatrix(x, r, c);

	for(i=0; i<r; i++) {
		free(a[i]);
		free(b[i]);
		free(x[i]);
	}

	free(a);
	free(b);
	free(x);

	return 0;
}

void readMatrix(int **a, int r, int c){
	int i,j;

	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}

void printMatrix(int **a, int r, int c){
	int i,j;

	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void matrixAdd(int **a, int **b, int **x, int r, int c){
	int i,j;

	for(i=0; i<r; i++) {
		for(j=0; j<c; j++) {
			x[i][j] = a[i][j] + b[i][j];
		}
	}
}
