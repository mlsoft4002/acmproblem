//���´�����Microsoft Visual Studio 2013��ͨ����
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<cmath>
#include<cstdlib>

bool isPrime(const int n)		//�ж�n�Ƿ�Ϊ����
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
		int n;									//����
		bool isFirst = true;					//�Ƿ�Ϊ��һ��������
		cin >> n;
		for (int i = 2; n != 1; ++i)
//����С��������2��ʼ���ж�ÿ�����Ƿ����������
//���nΪ1 (�������κ���������)�������
		{
			if (n % i == 0 && isPrime(i))		//���i��n��������
			{
				int exp = 0;					//ָ������ʼ��Ϊ��
				while (n%i == 0)				//һֱ������������Ϊֹ
				{
					++exp;
					n /= i;
				}
				if (isFirst)
//���ǰ���ж����ǲ��ǵ�һ���������أ�����ǵĻ�...
				{
					isFirst = false;
//��Ȼ����ǵ�һ���ˣ�������Ŀ϶��Ͳ��ǵ�һ����
					cout << i << "^" << exp;			//����ⲿ��
				}
				else									//������ǵĻ�...
				{
					cout << "*" << i << "^" << exp;
//������˺��������һ����
				}
			}
		}
		cout << endl;
	}
	return 0;
}
