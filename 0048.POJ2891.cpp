#include <cstdlib>
#include <iostream>
using namespace std;

__int64 result, d;
int flag;
__int64 gcd(__int64 a, __int64 b, __int64 &x, __int64 &y)
{
	__int64 t, ret;
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	ret = gcd(b, a%b, x, y);
	t = x;
	x = y;
	y = t - a / b*y;
	return ret;
}
void fun(__int64 a, __int64 b, __int64 n)
{
	__int64 x, y;
	d = gcd(a, n, x, y);
	if (b%d != 0)
		flag = 1;
	result = (x*(b / d) % n + n) % n;
}

int main(int argc, char *argv[])
{
	__int64 a1, m1, a2, m2, t;
	while (scanf("%I64d", &t) != EOF)
	{
		scanf("%I64d %I64d", &m1, &a1);
		t--;
		flag = 0;
		while (t--)
		{
			scanf("%I64d %I64d", &m2, &a2);
			fun(m1, a2 - a1, m2);
			a1 += m1*result;
			m1 = m1*m2 / d;
			a1 = (a1%m1 + m1) % m1;
		}
		if (flag)
			printf("-1\n");
		else
			printf("%I64d\n", a1);
	}
	return EXIT_SUCCESS;
}
