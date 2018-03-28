#include <cstdio>
#include <iostream>
using namespace std;

const int MOD = 10000;

int fast_mod(int n)    // �� (t^n)%MOD 
{
	int t[2][2] = { 1, 1, 1, 0 };
	int ans[2][2] = { 1, 0, 0, 1 };  // ��ʼ��Ϊ��λ����
	int tmp[2][2];    //��ʼ���ն���Ϊ����˷��е��м���� 

	while (n)
	{   //ʵ�� ans *= t; ����Ҫ�Ȱ� ans��ֵ�� tmp��Ȼ���� ans = tmp * t
		if (n & 1)  
		{
			for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				tmp[i][j] = ans[i][j];
			ans[0][0] = ans[1][1] = ans[0][1] = ans[1][0] = 0;  
// ע������Ҫ����ֵ�� 0 

			for (int i = 0; i < 2; ++i)    //  ����˷� 
			{
				for (int j = 0; j < 2; ++j)
				{
					for (int k = 0; k < 2; ++k)
						ans[i][j]=(ans[i][j]+tmp[i][k]*t[k][j])%MOD;
				}
			}
		}

	    //�±�Ҫʵ��  t *= t �Ĳ�����
//ͬ��Ҫ�Ƚ�t��ֵ���м����  tmp ��t���㣬֮�� t = tmp* tmp 
		for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			tmp[i][j] = t[i][j];
		t[0][0] = t[1][1] = 0;
		t[0][1] = t[1][0] = 0;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 2; ++k)
					t[i][j] = (t[i][j] + tmp[i][k] * tmp[k][j]) % MOD;
			}
		}

		n >>= 1;
	}
	return ans[0][1];
}

int main()
{
	int n;
	while (scanf("%d", &n) && n != -1)
	{
		printf("%d\n", fast_mod(n));
	}
	return 0;
}
