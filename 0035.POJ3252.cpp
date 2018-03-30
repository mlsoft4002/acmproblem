#include<stdio.h>
#include<iostream>
using namespace std;

int C[33][33];
int bits[33];

void init()
{
	C[0][0] = 1;
	C[1][0] = 1; C[1][1] = 1;
	for (int i = 2; i<33; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j<i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		C[i][i] = 1;
	}
}

int calc(int n)//求小于等于n的 Round Numbers
{
	if (n <= 1)return 0;//这个条件必须加
	int len = 0;
	while (n>0)
	{
		if (n & 1)bits[len++] = 1;
		else bits[len++] = 0;
		n >>= 1;
	}
	int ans = 0;
	for (int i = len - 1; i>0; i--)
	{
		if (i % 2 == 0)ans += ((1 << (i - 1))) / 2;
		else  ans += ((1 << (i - 1)) - C[i - 1][(i - 1) / 2]) / 2;
	}
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i<len; i++)
	{
		if (bits[i] == 0)cnt0++;
		else cnt1++;
	}
	if (cnt0 >= cnt1) ans++;//n本身是 Round Number
	cnt0 = 0;
	cnt1 = 1;

	for (int i = len - 2; i >= 0; i--)
	{
		if (bits[i] == 1)//后面有i位，第i位当成0
		{
			for (int j=i;j>=0&&j+cnt0+1>=i-j+cnt1;j--) ans+= C[i][j];
			cnt1++;
		}
		else cnt0++;
	}
	return ans;
}

int main()
{
	init();
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		printf("%d\n", calc(b) - calc(a - 1));
	}
	return 0;
}
