#���´�����Microsoft Visual Studio 2013��ͨ����
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<string>
using std::string;
#include<cstdlib>

string numpre(string& n)
{
	if (n.find(".") != string::npos)			//����С����
	{
		while (n[n.length() - 1] == '0')		//ȥ����������0
			n.erase(n.length() - 1, 1);
		if (n[n.length() - 1] == '.')			//��ȫΪ0��ɾ��С����
			n.erase(n.length() - 1, 1);
	}
	while (n.length() > 1 && n[0] == '0')	 //ǰ��0�Ĵ������ٱ���һ��0
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
