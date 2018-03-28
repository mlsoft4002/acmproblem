#include<stdio.h>  

int pow_mod(int a, int b, int c){
	int res = 1;
	a = a%c;
	while (b){
		if (b & 1)
			res = (res * a) % c;
		a = a *a % c;b >>= 1;
	}
	return res;
}

int main()
{
	int n, res, test;
	scanf("%d", &test);
	while (test--){
		scanf("%d", &n);
		res = pow_mod(2, n - 1, 10007);
		res = res * (res + 1);
		printf("%d\n", res % 10007);
	}
	return 0;
}
