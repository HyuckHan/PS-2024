#include <stdio.h>

int comb(int n, int r) {
	if(r==0 || r==n)
		return 1;
	else
		return comb(n-1,r-1) + comb(n-1, r);
}

int main() {
	int n, r;

	/*scanf("%d", &n);
	scanf("%d", &r);*/
	n = 32;
	r = 16;

	printf("%d\n", comb(n,r));
	return 0;
}
