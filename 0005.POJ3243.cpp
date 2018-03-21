#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 65535;

struct Hash
{
	int a, b, next;
}hash[maxn << 1];

int flg[maxn];
int top, idx;

void ins(int a, int b)	//插入hash表(i, A^i mod C)
{
	int k = b & maxn;   /////////
	if(flg[k] != idx)
	{
		flg[k] = idx;
		hash[k].next = -1;
		hash[k].a = a;
		hash[k].b = b;
		return;
	}
	while(hash[k].next != -1)
	{
		if(hash[k].b == b) return ;
		k = hash[k].next;
	}
	hash[k].next = ++top;
	hash[top].next = -1;
	hash[top].a = a;
	hash[top].b = b;
}

int find(int b)		//查找
{
	int k = b & maxn;
	if(flg[k] != idx) return -1;
	while(k != -1)
	{
		if(hash[k].b == b) return hash[k].a;
		k = hash[k].next;
	}
	return -1;
}

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int ext_gcd(int a, int b, int &x, int &y)
{
	int t, ret;
	if( !b)
	{
		x = 1; y = 0;
		return a;
	}
	ret = ext_gcd(b, a%b, x, y);
	t = x, x = y, y = t - a/b * y;
	return ret;
}

int Inval(int a, int b, int n)	//返回 D*X = B (mod C) 中的X值；
{
	int x, y, e;
	ext_gcd(a, n, x, y);
	e = (__int64) x * b % n;
	return e < 0 ? e + n : e;
}

int pow_mod(__int64 a, int b, int c)	//a^b mod c
{
	__int64 ret = 1 % c;
	a %= c;
	while(b)
	{
		if(b & 1) ret = ret * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return ret;
}

int BabyStep(int A, int B, int C)
{
	top = maxn;
	++idx;
	__int64 buf = 1 % C, D = buf, k;
	int i, d = 0, tmp;
	for(i=0; i<=100; buf=buf*A%C, ++i)	//buf = A^i mod C
		if(buf == B) return i;			//如果存在A^i mod C = B,,
	while((tmp=gcd(A, C)) != 1)
	{
		if(B % tmp) return -1;		//无解；
		++d;
		C /= tmp;
		B /= tmp;
		D = D * A/tmp % C;
	}
	int M = (int)ceil(sqrt(C*1.0));		//必要的
	for(buf=1%C, i=0; i<=M; buf=buf*A%C, ++i) 
		ins(i, buf);	//插入hash表(i, A^i mod C)
	for(i=0, k=pow_mod((__int64)A, M, C); i<=M; D=D*k%C, ++i)
	{
		tmp = Inval((int)D, B, C); 
//D*X = B (mod C) 的唯一解（如果存在解，必然唯一）；
		int w;
		if(tmp > 0 && (w = find(tmp)) != -1) 
//find()之后hash表中查询，若查到（假设是j），则return i*m + j;
			return i * M + w + d;
	}		//否则D = D*K % C，继续循环；
	return -1;	//无条件返回-1，无解；
}

int main()
{
	int A, B, C;
	while(scanf("%d%d%d",&A,&C,&B) != EOF, A || B ||C)
	{
		B %= C;
		int tmp = BabyStep(A, B, C);
		if(tmp < 0)
			printf("No Solution/n");
		else
			printf("%d/n",tmp);
	}
	return 0;
}
