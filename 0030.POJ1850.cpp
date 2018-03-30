#include<iostream>
#include<string>
using namespace std;

int c[27][27] = { 0 };

void play_table(void)
{
	for (int i = 0; i <= 26; i++)
	for (int j = 0; j <= i; j++)
	if (!j || i == j)
		c[i][j] = 1;
	else
		c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	c[0][0] = 0;
	return;
}

int main()
{
	int i;
	int j;
	play_table();
	char str[11];
	while (cin >> str)
	{
		int len = strlen(str);
		for (i = 1; i<len; i++)
		if (str[i - 1] >= str[i])
		{
			cout << 0 << endl;   //����ֻҪ������һ�ξ������������
			return 0;        
//��ʹ��ѭ�����룬һ��str������Ҫ����aab,ba�ȣ��ͽ�������
		}  //������POJ1496������������
		int sum = 0;  //str��ֵ����ʼΪ0
		for (i = 1; i<len; i++)
			sum += c[26][i];  //c[26][i]��ʾ����Ϊi���ַ����ĸ���
		for (i = 0; i<len; i++)  
//iΪstr��ָ�룬��ÿһ��λ��ö������ѡ����ַ�ch
		{
			char ch = (!i) ? 'a' : str[i - 1] + 1;   
//ch = str[i-1]+1�����������
//��ǰλ�õ�ch����Ҫ��strǰһλ�õ��ַ���1
			while (ch <= str[i] - 1)   
//ch<=str[i]-1�����������
//��ǰλ�õ�ch���ֻ�ܱ�str���λ��ʵ���ϵ��ַ�С1
			{
				sum += c['z' - ch][len - 1 - i];  
//'z'-ch��С�ڵ���ch���ַ��������ٱ�ѡ��
//���Ե�ǰ�ܹ�ѡ����ַ�����Ϊ'z'-ch
				ch++; //len-1-i  ��chλ�ú��棨������ch��ʣ�µ�λ����
//���Ǵ�'z'-chѡ��len-1-i���ַ�
			}
		}
		cout << ++sum << endl; //��ǰ�Ĳ�������Ѱ�ұ�strС��
//�����ַ����ĸ�������������str�����������Ҫ+1
	}
	return 0;
}
