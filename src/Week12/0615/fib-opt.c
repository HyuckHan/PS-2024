#include <stdio.h>
#include <stdlib.h>

long fib(int n, long *m) {
	if(n == 1 || n == 2)
		return 1;
	else{
		if(m[n-1] == 0)
			m[n-1] = fib(n-1, m);
		if(m[n-2] == 0)
			m[n-2] = fib(n-2, m);
		return m[n-1]+m[n-2];
	}
}

long fib2(int n, long *m) {
	if(m[n] != 0) 
		return m[n];

	if(n == 1 || n == 2)
		return 1;
	else {
		m[n] = fib2(n-1, m) + fib2(n-2, m);
		return m[n];
	}
}

int main() {
	int n, i;
	long *m;
	//scanf("%d", &n);
	n = 44;
	
	m = (long*) malloc(sizeof(long)*(n+1));
	for(i=0; i<n+1; i++)
		m[i] = 0;
	printf("%ld\n",fib(n,m));

	/*for(i=0; i<n+1; i++)
		m[i] = 0;
	printf("%ld\n",fib2(n,m));*/

	return 0;
}









