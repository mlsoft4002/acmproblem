//��C++����ʵ��
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<algorithm>
using std::max;
#include<cstdlib>

string stringAdd(const string& a, const string& b)
{
	string::size_type length = max(a.length(), b.length()) + 1;
//������������ܻ���max+1λ
	string lhd = string(length - a.length(), '0').append(a);
//���������������0�Ա��Ҷ���
	string rhd = string(length - b.length(), '0').append(b);
//�Ҳ�������������0�Ա��Ҷ���
	string result(length, '0');				//��ź�
	int carry = 0;								//��Ž�λ
	for (string::size_type ix=length-1; ix < length; --ix)//����������
	{
		int ans = lhd[ix] + rhd[ix] - 2 * '0' + carry;
		result[ix] = ans % 10 + '0';
		carry = ans / 10;
	}
	while (result.length() > 1 && result[0] == '0')
//ǰ��0�Ĵ������ٱ���һ��0
		result.erase(0, 1);
	return result;
}

int main(void)
{
	int k;
	cin >> k;
	while (k--){
		string num;
		string result("0");
		for (int i = 0; i != 4; ++i){
			cin >> num;
			result = stringAdd(result, num);
		}
		cout << result << endl;
	}
	return 0;
}
