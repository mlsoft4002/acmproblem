#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define LL __int64
using namespace std;

const int MAXN = 65535;

struct HASH
{
	int a;
	int b;
	int next;
}Hash[MAXN * 2];

int flag[MAXN + 66];
int top, idx;

void ins(int a, int b)
{
	int k = b & MAXN;
	if (flag[k] != idx)
	{
		flag[k] = idx;
		Hash[k].next = -1;
		Hash[k].a = a;
		Hash[k].b = b;
		return;
	}

	while (Hash[k].next != -1)
	{
		if (Hash[k].b == b)
			return;
		k = Hash[k].next;
	}
	Hash[k].next = ++top;
	Hash[top].next = -1;
	Hash[top].a = a;
	Hash[top].b = b;
}

int Find(int b)
{
	int k = b & MAXN;
	if (flag[k] != idx)
		return -1;
	while (k != -1)
	{
		if (Hash[k].b == b)
			return Hash[k].a;
		k = Hash[k].next;
	}
	return -1;
}

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

int ExGCD(int a, int b, int &x, int &y)
{
	int temp, ret;
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	ret = ExGCD(b, a%b, x, y);
	temp = x;
	x = y;
	y = temp - a / b*y;
	return ret;
}

int Inval(int a, int b, int n)
{
	int x, y, e;
	ExGCD(a, n, x, y);
	e = (LL)x*b%n;
	return e < 0 ? e + n : e;
}

int PowMod(LL a, int b, int c)
{
	LL ret = 1 % c;
	a %= c;
	while (b)
	{
		if (b & 1)
			ret = ret*a%c;
		a = a*a%c;
		b >>= 1;
	}
	return ret;
}

int BabyStep(int A, int B, int C)
{
	top = MAXN;
	++idx;
	LL buf = 1 % C, D = buf, K;
	int d = 0, temp, i;
	for (i = 0; i <= 100; buf = buf*A%C, ++i)
	{
		if (buf == B)
			return i;
	}

	while ((temp = GCD(A, C)) != 1)
	{
		if (B % temp)
			return -1;
		++d;
		C /= temp;
		B /= temp;
		D = D*A / temp%C;
	}

	int M = (int)ceil(sqrt((double)C));
	for (buf = 1 % C, i = 0; i <= M; buf = buf*A%C, ++i)
		ins(i, buf);

	for (i = 0, K = PowMod((LL)A, M, C); i <= M; D = D*K%C, ++i)
	{
		temp = Inval((int)D, B, C);
		int w;
		if (temp >= 0 && (w = Find(temp)) != -1)
			return i * M + w + d;
	}
	return -1;
}

int main()
{
	int A, B, C;
	while (~scanf("%d%d%d", &A, &C, &B))
	{
		if (B > C)
		{
			printf("Orz,I can¡¯t find D!\n");
			continue;
		}
		B %= C;
		int temp = BabyStep(A, B, C);
		if (temp < 0)
			printf("Orz,I can¡¯t find D!\n");
		else
			printf("%d\n", temp);
	}

	return 0;
}
