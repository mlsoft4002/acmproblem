#include <stdio.h>
#define MAXSIZE 4

/* find ans s.t. (ans * y) % x = r*/
int remaind(int x, int y, int r)
{
	int i = 0, temp = y%x;
	for (i = x - 1; i; i--)
	if ((i*temp) % x == r)
		break;
	return i;
}

int main()
{
	int cases = 1, ans = 0, d = 0, totalProduct, i = 0;
	const int len = 3;
	int in[MAXSIZE];
	int m[MAXSIZE];
	int circle[MAXSIZE] = { 23, 28, 33 };

	totalProduct = 1;
	for (i = 0; i<len; i++)
		totalProduct *= circle[i];
	for (i = 0; i<len; i++)
		m[i] = totalProduct / circle[i];

	while (scanf("%d %d %d %d", &in[0], &in[1], &in[2], &d))
	{
		if (in[0] == -1)
			break;

		for (i = 0; i<len; i++)
			in[i] %= circle[i];

		ans = 0;
		for (i = 0; i<len; i++)
			ans += remaind(circle[i], m[i], in[i])*m[i];

		ans = ans + totalProduct - d % totalProduct;
		ans %= totalProduct;

		if (ans == 0)
			ans = totalProduct;

		printf("Case %d: the next triple peak occurs in %d days.\n",
			cases++, ans);
	}
}
