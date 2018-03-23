#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;

const int maxn = 310;
int equ, var; // 有equ个方程，var个变元。
//增广阵行数为equ, 分别为0到equ - 1，列数为var + 1，分别为0到var.
int a[maxn][maxn];//增广矩阵
int x[maxn]; // 解集.
int free_num;

inline int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

inline int lcm(int a, int b)
{
	return a*b / gcd(a, b);
}

// 高斯消元法解方程组(Gauss-Jordan elimination).
//(-2表示有浮点数解，但无整数解，-1表示无解，
//0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
int change(char s[])
{
	if (strcmp(s, "MON") == 0) return 1;
	else if (strcmp(s, "TUE") == 0) return 2;
	else if (strcmp(s, "WED") == 0) return 3;
	else if (strcmp(s, "THU") == 0) return 4;
	else if (strcmp(s, "FRI") == 0) return 5;
	else if (strcmp(s, "SAT") == 0) return 6;
	else  return 7;
}

int Gauss(void)
{
	int i, j, k;
	int max_r; // 当前这列绝对值最大的行.
	int col; // 当前处理的列.
	int ta, tb;
	int LCM;
	int temp;
	// 转换为阶梯阵.
	col = 0; // 当前处理的列.
	for (k = 0; k < equ && col < var; k++, col++)
	{ // 枚举当前处理的行.
	 //找到该col列元素绝对值最大的那行与第k行交换.(为在除法时减小误差)
		max_r = k;
		for (i = k + 1; i < equ; i++)
		{
			if (abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
		}
		if (max_r != k)
		{ // 与第k行交换.
			for (j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
		}
		if (a[k][col] == 0)
		{ // 说明该col列第k行以下全是0了，则处理当前行的下一列.
			k--;
			continue;
		}
		for (i = k + 1; i < equ; i++)
		{ // 枚举要删去的行.
			if (a[i][col] != 0)
			{
				LCM = lcm(abs(a[i][col]), abs(a[k][col]));
				ta = LCM / abs(a[i][col]), tb = LCM / abs(a[k][col]);
				if (a[i][col] * a[k][col] < 0) tb = -tb; 
// 异号的情况是两个数相加.
				for (j = col; j < var + 1; j++)
				{
					a[i][j]=(((a[i][j] * ta-a[k][j]*tb)%7 + 7) % 7);
				}
			}
		}
	}
	//Debug();
	// 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
	for (i = k; i < equ; i++)
	{ //对于无穷解来说，如果要判断哪些是自由变元，
//那么初等行变换中的交换就会影响，则要记录交换.
		if (a[i][col] != 0) return -1;
	}
	// 2. 无穷解的情况: 在var * (var + 1)的增广阵中
//出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
	// 且出现的行数即为自由变元的个数.
	if (k < var)
		return var - k; // 自由变元有var - k个.
	// 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
	// 计算出Xn-1, Xn-2 ... X0.
	for (i = var - 1; i >= 0; i--)
	{
		temp = a[i][var];//等式右边的数
		for (j = i + 1; j < var; j++)
		{
			if (a[i][j] != 0) temp -= a[i][j] * x[j];
//把已知的解带入，减去，只剩下，一个未知的解
			temp = (temp % 7 + 7) % 7;
		}
		while (temp%a[i][i] != 0)//外层每次循环都是为了求 a[i][i],
//因为它是每个方程中唯一一个未知的变量（求该方程时）
			temp += 7;
//因为天数不确定，而a[i][i]必须得为整数才可以，周期为7
		    x[i] = (temp / a[i][i]) % 7;
	}
	return 0;
}

int main(void)
{
	int n, m, k, num;
	char s[5], e[5];
	while (scanf("%d%d", &n, &m) != EOF && (n || m))
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i<m; i++)
		{
			scanf("%d", &k);
			scanf("%s%s", s, e);
			a[i][n] = ((change(e) - change(s) + 1) % 7 + 7) % 7;
			for (int j = 1; j <= k; j++)//k是他打造的数量
			{
				scanf("%d", &num);//可能是相同的数
				num--;
				a[i][num]++;//系数++
				a[i][num] %= 7;//有重复的。
			}
		}
		equ = m;//有m个方程
		var = n;//有多少个变量
		free_num = Gauss();
		if (free_num == 0)
		{
			for (int i = 0; i<n; i++)
//根据题意，每个零件的加工时间在3-9天.
			if (x[i] <= 2)
				x[i] += 7;
			for (int i = 0; i<n - 1; i++)
				cout << x[i] << " ";
			cout << x[n - 1] << endl;
		}
		else if (free_num == -1)
			cout << "Inconsistent data." << endl;
		else
			cout << "Multiple solutions." << endl;
	}
	return 0;
}
