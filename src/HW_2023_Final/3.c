#include <stdio.h>
#include <stdlib.h>

long k_bonacci(int n, int k, long *M) {
	if(M[n] != 0)
		return M[n];

	if(n<=k)
		return 1;
	else{
		int i = 0;
		M[n] = 0;
		for(i=1; i<=k ;i++)
			M[n] = M[n] + k_bonacci(n-i,k,M);
		return M[n];
	}
}

int main() {
	int n,i,k;
	long *M;

	scanf("%d", &n);
	scanf("%d", &k);

	M = (long*) malloc(sizeof(long)*(n+1));
	for(i=0; i<n+1; i++)
		M[i] = 0;

	printf("%ld\n", k_bonacci(n, k, M));
	return 0;
}
