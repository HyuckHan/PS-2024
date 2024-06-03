#include <stdio.h>
#include <stdlib.h>

long t_bonacci(int n, long *M) {
	if(M[n] != 0)
		return M[n];

	if(n<=3)
		return 1;
	else{
		M[n] = t_bonacci(n-1, M) + t_bonacci(n-2, M) + t_bonacci(n-3, M);
		return M[n];
	}
}

int main() {
	int n,i;
	long *M;

	scanf("%d", &n);

	M = (long*) malloc(sizeof(long)*(n+1));
	for(i=0; i<n+1; i++)
		M[i] = 0;

	printf("%ld\n", t_bonacci(n, M));
	return 0;
}
