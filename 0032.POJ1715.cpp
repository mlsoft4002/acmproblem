#include <iostream>
#include <cstring>
#define MAX_N 350000
using namespace std;

char base[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
char res[16];
int num;

//����������A(x, y)
int getAxy(int x, int y)
{
	if (y == 0) return 1;
	int res = 1;
	while (y--)
	{
		res *= x;
		x--;
	}
	return res;
}

void getRes()
{
	int curPos;
	bool v[MAX_N + 1];
	memset(v, 0, sizeof(v));
	int useFulLen = 0;
	bool foundHead = false;
	//�Ӹ�λ����λ����
	for (curPos = 1; curPos <= 8; curPos++)
	{
		int curNum = 15;
		int countv;
		//һ�α�����ǰλ���п��ܵ�ȡֵ
		while (curNum >= 1)
		{
			if (!v[curNum])
			{
				//countv�ǵ�ǰλȡcurNumʱ,���Ժ��ǵ����ĸ���
				if((countv=getAxy(16-1-useFulLen, 8-curPos))< num)
					num -= countv; //�����Ժ���,��num��ȥ���ֵ
				else //���Ժ���
				{
					v[curNum] = true;
					break;
				}
			}
			curNum--;
		}
		res[curPos] = base[curNum];
		//Ҫע��ͳ�Ƶ�ǰ��Чλ�ĳ���
		if (foundHead || res[curPos] != '0') useFulLen++;
		if (res[curPos] != '0') foundHead = true;
	}
}

int main()
{
	while (scanf("%d", &num) != EOF)
	{
		getRes();
		bool findHead = false;
		for (int i = 1; i <= 8; i++)
		{
			if (findHead || res[i] != '0')
				printf("%c", res[i]);
			if (!findHead && res[i] != '0')
				findHead = true;
		}
		if (!findHead) printf("0");
		printf("/n");
	}
	return 0;
}
