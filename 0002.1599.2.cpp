//用C++语言实现
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
//两数相加最大可能会有max+1位
	string lhd = string(length - a.length(), '0').append(a);
//左操作数，左边填充0以便右对齐
	string rhd = string(length - b.length(), '0').append(b);
//右操作数，左边填充0以便右对齐
	string result(length, '0');				//存放和
	int carry = 0;								//存放进位
	for (string::size_type ix=length-1; ix < length; --ix)//从右往左算
	{
		int ans = lhd[ix] + rhd[ix] - 2 * '0' + carry;
		result[ix] = ans % 10 + '0';
		carry = ans / 10;
	}
	while (result.length() > 1 && result[0] == '0')
//前置0的处理，至少保存一个0
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
