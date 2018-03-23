#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;

const int maxn = 310;
int equ, var; // ��equ�����̣�var����Ԫ��
//����������Ϊequ, �ֱ�Ϊ0��equ - 1������Ϊvar + 1���ֱ�Ϊ0��var.
int a[maxn][maxn];//�������
int x[maxn]; // �⼯.
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

// ��˹��Ԫ���ⷽ����(Gauss-Jordan elimination).
//(-2��ʾ�и������⣬���������⣬-1��ʾ�޽⣬
//0��ʾΨһ�⣬����0��ʾ����⣬���������ɱ�Ԫ�ĸ���)
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
	int max_r; // ��ǰ���о���ֵ������.
	int col; // ��ǰ�������.
	int ta, tb;
	int LCM;
	int temp;
	// ת��Ϊ������.
	col = 0; // ��ǰ�������.
	for (k = 0; k < equ && col < var; k++, col++)
	{ // ö�ٵ�ǰ�������.
	 //�ҵ���col��Ԫ�ؾ���ֵ�����������k�н���.(Ϊ�ڳ���ʱ��С���)
		max_r = k;
		for (i = k + 1; i < equ; i++)
		{
			if (abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
		}
		if (max_r != k)
		{ // ���k�н���.
			for (j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
		}
		if (a[k][col] == 0)
		{ // ˵����col�е�k������ȫ��0�ˣ�����ǰ�е���һ��.
			k--;
			continue;
		}
		for (i = k + 1; i < equ; i++)
		{ // ö��Ҫɾȥ����.
			if (a[i][col] != 0)
			{
				LCM = lcm(abs(a[i][col]), abs(a[k][col]));
				ta = LCM / abs(a[i][col]), tb = LCM / abs(a[k][col]);
				if (a[i][col] * a[k][col] < 0) tb = -tb; 
// ��ŵ���������������.
				for (j = col; j < var + 1; j++)
				{
					a[i][j]=(((a[i][j] * ta-a[k][j]*tb)%7 + 7) % 7);
				}
			}
		}
	}
	//Debug();
	// 1. �޽�����: ������������д���(0, 0, ..., a)��������(a != 0).
	for (i = k; i < equ; i++)
	{ //�����������˵�����Ҫ�ж���Щ�����ɱ�Ԫ��
//��ô�����б任�еĽ����ͻ�Ӱ�죬��Ҫ��¼����.
		if (a[i][col] != 0) return -1;
	}
	// 2. ���������: ��var * (var + 1)����������
//����(0, 0, ..., 0)�������У���˵��û���γ��ϸ����������.
	// �ҳ��ֵ�������Ϊ���ɱ�Ԫ�ĸ���.
	if (k < var)
		return var - k; // ���ɱ�Ԫ��var - k��.
	// 3. Ψһ������: ��var * (var + 1)�����������γ��ϸ����������.
	// �����Xn-1, Xn-2 ... X0.
	for (i = var - 1; i >= 0; i--)
	{
		temp = a[i][var];//��ʽ�ұߵ���
		for (j = i + 1; j < var; j++)
		{
			if (a[i][j] != 0) temp -= a[i][j] * x[j];
//����֪�Ľ���룬��ȥ��ֻʣ�£�һ��δ֪�Ľ�
			temp = (temp % 7 + 7) % 7;
		}
		while (temp%a[i][i] != 0)//���ÿ��ѭ������Ϊ���� a[i][i],
//��Ϊ����ÿ��������Ψһһ��δ֪�ı�������÷���ʱ��
			temp += 7;
//��Ϊ������ȷ������a[i][i]�����Ϊ�����ſ��ԣ�����Ϊ7
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
			for (int j = 1; j <= k; j++)//k�������������
			{
				scanf("%d", &num);//��������ͬ����
				num--;
				a[i][num]++;//ϵ��++
				a[i][num] %= 7;//���ظ��ġ�
			}
		}
		equ = m;//��m������
		var = n;//�ж��ٸ�����
		free_num = Gauss();
		if (free_num == 0)
		{
			for (int i = 0; i<n; i++)
//�������⣬ÿ������ļӹ�ʱ����3-9��.
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
