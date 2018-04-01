//以下代码在Microsoft Visual Studio 2013中通过。
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<cmath>
#include<cstdlib>

bool isPrime(const int n)		//判断n是否为质数
{
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	int k = int(sqrt(n));
	for (int i = 3; i <= k; i += 2){
		if (n%i == 0) return false;
	}
	return true;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--){
		int n;									//该数
		bool isFirst = true;					//是否为第一个质因子
		cin >> n;
		for (int i = 2; n != 1; ++i)
//从最小的质因数2开始，判断每个数是否符合条件，
//如果n为1 (不包含任何质因数了)，则结束
		{
			if (n % i == 0 && isPrime(i))		//如果i是n的质因数
			{
				int exp = 0;					//指数，初始化为零
				while (n%i == 0)				//一直除到不能整除为止
				{
					++exp;
					n /= i;
				}
				if (isFirst)
//输出前得判断它是不是第一个质因子呢，如果是的话...
				{
					isFirst = false;
//既然这就是第一个了，那下面的肯定就不是第一个了
					cout << i << "^" << exp;			//输出这部分
				}
				else									//如果不是的话...
				{
					cout << "*" << i << "^" << exp;
//先输出乘号再输出这一部分
				}
			}
		}
		cout << endl;
	}
	return 0;
}
