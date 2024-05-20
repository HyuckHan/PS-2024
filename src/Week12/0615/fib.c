#include <stdio.h>

long fib(int n) {
	if(n == 1 || n == 2)
		return 1;
	else
		return fib(n-1) + fib(n-2);
}

int main() {
	int n;
	//scanf("%d", &n);
	n = 44;

	printf("%ld\n",fib(n));

	return 0;
}
