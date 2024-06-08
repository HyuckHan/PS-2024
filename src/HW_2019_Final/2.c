#include <stdio.h>
#include <stdlib.h>

long H(int n, long *M) {

	if(M[n] != 0)
		return M[n];

	if(n == 1) {
		return 1;
	}
	else {
		int i;

		for(i=1; i<n; i++) 
			M[n] = M[n] + (n-i)*H(i, M);

		return M[n];

	}

}

int main() {
	int n, i;
	long *M;

	scanf("%d", &n);
	M = (long*) malloc(sizeof(long)*(n+1));
	for(i=0; i<n+1; i++)
		M[i] = 0;
	
	printf("%ld\n", H(n,M));
	free(M);
	return 0;
}
