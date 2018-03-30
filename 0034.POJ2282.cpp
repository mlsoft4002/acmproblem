#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

void Cal(char *s, int *num)
{
	int i, j, k, n, t, m = atoi(s);
	n = (int)strlen(s);
	for (i = k = 1; i<n; i++)
		k *= 10, num[0] -= k;
	for (i = 0; i<n; i++, k /= 10)
	{
		for (j = 0; j<s[i] - '0'; j++)
			num[j] += k;
		for (t = 0; t<10; t++)
			num[t] += k / 10 * (n - i - 1)*j;
		if (i + 1<n)
			num[j] += atoi(s + i + 1);
		num[j]++;
	}
}

int main()
{
	char s[22];
	int i, n, m, a[11] = { 0 }, b[11] = { 0 };
	while(scanf("%d%d", &n, &m), m + n)
	{
		if (n>m)
			swap(n, m);
		memset(a, 0, sizeof(a));
		sprintf(s, "%d", n - 1);
		Cal(s, a);
		memset(b, 0, sizeof(b));
		sprintf(s, "%d", m);
		Cal(s, b);
		for (i = 0; i<10; i++)
			printf("%d ", b[i] - a[i]);
		puts("");
	}
	return 0;
}
