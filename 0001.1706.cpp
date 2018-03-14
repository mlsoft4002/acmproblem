#以下代码在Microsoft Visual Studio 2013中通过。
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<cstdlib>

string numpre(string& n)
{
	if (n.find(".") != string::npos)			//若有小数点
	{
		while (n[n.length() - 1] == '0')		//去除后面多余的0
			n.erase(n.length() - 1, 1);
		if (n[n.length() - 1] == '.')			//若全为0，删除小数点
			n.erase(n.length() - 1, 1);
	}
	while (n.length() > 1 && n[0] == '0')	 //前置0的处理，至少保存一个0
		n.erase(0, 1);
	return n;
}

int main(){
	string a, b;
	while (cin >> a >> b){
		if (numpre(a) == numpre(b))	puts("YES");
		else	 puts("NO");
	}
	return 0;
}
