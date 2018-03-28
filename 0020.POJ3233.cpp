#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n, k, mod;

struct Matrix{
	int arr[40][40];
};

Matrix unit, init;

Matrix Mul(Matrix a, Matrix b){
	Matrix c;
	for (int i = 0; i<n; i++)
	for (int j = 0; j<n; j++){
		c.arr[i][j] = 0;
		for (int k = 0; k<n; k++)
			c.arr[i][j]=(c.arr[i][j]+a.arr[i][k]*b.arr[k][j]%mod)%mod;
		c.arr[i][j] %= mod;
	}
	return c;
}

Matrix Pow(Matrix a, Matrix b, int x){
	while (x){
		if (x & 1){
			b = Mul(b, a);
		}
		x >>= 1;
		a = Mul(a, a);
	}
	return b;
}

Matrix Add(Matrix a, Matrix b){
	Matrix c;
	for (int i = 0; i<n; i++)
	for (int j = 0; j<n; j++)
		c.arr[i][j] = (a.arr[i][j] + b.arr[i][j]) % mod;
	return c;
}

Matrix solve(int x){
	if (x == 1)
		return init;
	Matrix res = solve(x / 2), cur;
	if (x & 1){
		cur = Pow(init, unit, x / 2 + 1);
		res = Add(res, Mul(cur, res));
		res = Add(res, cur);
	}
	else{
		cur = Pow(init, unit, x / 2);
		res = Add(res, Mul(cur, res));
	}
	return res;
}

int main(){
	while (~scanf("%d%d%d", &n, &k, &mod))
{
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++){
			scanf("%d", &init.arr[i][j]);
			unit.arr[i][j] = (i == j ? 1 : 0);
		}
		Matrix res = solve(k);
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n - 1; j++)
				printf("%d ", res.arr[i][j]);
			printf("%d\n", res.arr[i][n - 1]);
		}
	}
	return 0;
}
