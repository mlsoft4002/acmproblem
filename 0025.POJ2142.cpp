#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f

int exgcd(int a, int b, int &x, int &y)
{
if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	int d = exgcd(b, a%b, x, y);
	int tmp = x;
	x = y;
	y = tmp - a / b*y;
	return d;
}

int main()
{
	int a, b, c, x, y;
	bool flag;
	while (cin >> a >> b >> c && a | b | c)
	{
		flag = false;
		if (a<b)
		{
			swap(a, b);
			flag = true;
		}
		int r = exgcd(a, b, x, y);
		a /= r; b /= r; c /= r;
		x *= c; y *= c;
		int t = y / a;
		int rx, ry;
		while (y - a*t<0)
			t--;
		int x1, y1, x2, y2;
		x1 = abs(x + b*t);
		y1 = abs(y - a*t);
		t++;
		x2 = abs(x + b*t); y2 = abs(y - a*t);
		if ((x1 + y1<x2 + y2) || ((x1 + y1 == x2 + y2) 
&& (x1*a + y1*b<x2*a+ y2*b))
			rx = x1, ry = y1;
		else
			rx = x2, ry = y2;
		if (flag)
			cout << ry << ' ' << rx << endl;
		else
			cout << rx << ' ' << ry << endl;
		}
	return 0;
}
