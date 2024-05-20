#include <stdio.h>

long H(int n) {
	if(n<2)
		return 1;
	else {
		long ret = 0;
		int i;

		for(i=0; i<n; i++)
			ret = ret + H(i)*H(n-i-1);
		return ret;
	}
}

int main(void)
{
	int n;
	//scanf("%d", &n);
	n = 20;
	printf("%ld\n", H(n));
	return 0;
}
