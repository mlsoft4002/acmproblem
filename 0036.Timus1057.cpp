#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define Del(a,b) memset(a,b,sizeof(a))

typedef long long LL;
const double esp = 1e-10;
const int N = 50;
int f[N][N]; //f[i][j] ǰi����ѡj��1�ĸ���

void isit()
{
	f[0][0] = 1;
	for (int i = 1; i<33; i++){
		f[i][0] = f[i - 1][0];
		for (int j = 1; j <= i; j++){
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
		}
	}
}

int solve(int x, int k, int c)
{
	vector<int> v;
	while (x)
	{
		v.push_back(x%c);
		x /= c;
	}
	int cnt = 0, ans = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] == 1) //Ϊ1�����������
		{
			ans += f[i][k - cnt];
			cnt++;
			if (cnt == k)
				break;
		}
		else if (v[i]>1) 
//�������1�Ļ����൱�����е�λ�п���Ϊ1������ֱ���������
		{
			ans += f[i + 1][k - cnt];
			break;
		}
	}
	if (cnt == k)
		ans++;
	return ans;
}

int main()
{
	isit();
	int x, y, k, c;
	while (~scanf("%d%d%d%d", &x, &y, &k, &c))
	{
		printf("%d\n", solve(y, k, c) - solve(x - 1, k, c));
	}
	return 0;
}
