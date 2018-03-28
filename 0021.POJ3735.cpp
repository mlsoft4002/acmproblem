#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int mm = 111;
__int64 a[mm][mm], b[mm][mm], c[mm][mm];
int i, j, e, n, m, k;
char op[9];

void Multi(__int64 a[mm][mm], __int64 b[mm][mm])
{
	memset(c, 0, sizeof(c));
	int i, j, k;
	for (i = 1; i <= n + 1; ++i)
	for (k = 1; k <= n + 1; ++k)
	if (a[i][k])for (j = 1; j <= n + 1; ++j)
	if (b[k][j])c[i][j] += a[i][k] * b[k][j];
	for (i = 1; i <= n + 1; ++i)
	for (j = 1; j <= n + 1; ++j)
		a[i][j] = c[i][j];
}

int main()
{
	while (scanf("%d%d%d", &n, &m, &k), n + m + k){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (i = 1; i <= n + 1; ++i)a[i][i] = b[i][i] = 1;
		while (k--)	{
			scanf("%s%d", op, &i);
			if (op[0] == 'g')++a[i][n + 1];
			if (op[0] == 'e')
			for (j = 0; j <= n + 1; ++j)a[i][j] = 0;
			if (op[0] == 's'){
				scanf("%d", &j);
				for (e = 1; e <= n + 1; ++e)
					swap(a[i][e], a[j][e]);
			}
		}
		while (m){
			if (m & 1)Multi(b, a);
			Multi(a, a);
			m >>= 1;
		}
		for (i = 1; i <= n; ++i)
			printf("%I64d%c", b[i][n + 1], i<n ? ' ' : '\n');
	}
	return 0;
}
