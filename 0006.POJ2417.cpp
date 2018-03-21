#include <cstdio>
#include <cstring>
#include <cmath>

#define Prime 899037
#define oo 2000000005
#define min(a, b) ((a)<(b) ? (a) : (b))
int P, B, N;
int H[Prime], V[Prime];

inline int pow(int u, int v)
{
	int ret = 1;
	for (int tmp = u; v; v >>= 1, tmp = (tmp*(long long)tmp) % P)
	if (v & 1)    ret = (ret*(long long)tmp) % P;
	return ret;
}

inline void Hpush(int u, int v)
{
	int t = u%Prime;
	for (; H[t];)
	{
		if (H[t] == u)    return;
		if (++t == P)    t -= P;
	}
	H[t] = u, V[t] = v;
}

inline int Hpop(int u)
{
	int t = u%Prime;
	for (; H[t];)
	{
		if (H[t] == u)    return V[t];
		if (++t == P)    t -= P;
	}
	return oo;
}

int main()
{
	for (; scanf("%d%d%d", &P, &B, &N) != EOF;)
	{
		int ret = oo + 1;
		memset(H, 0, sizeof(H));
		memset(V, -1, sizeof(V));
		int sqrtP = (int)sqrt((double)P), Bsp = pow(B, sqrtP);
		for (int i=0,val=1;i<=sqrtP;++i,val=(val*(long long)Bsp)%P)
			Hpush(val, i);
		for (int i=0,val=1;i<=sqrtP;++i,val=(val*(long long)B)%P)
		{
			int h = (N*(long long)pow(val, P - 2)) % P, v = Hpop(h);
			if (v < oo && v*sqrtP + i<ret)
				ret = v*sqrtP + i;
		}
		if (ret > oo)
			puts("no solution");
		else
			printf("%d\n", ret);
	}
	return 0;
}
