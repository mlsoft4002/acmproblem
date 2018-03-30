#include <iostream>
#include <cstring>
#define MAX_N 350000
using namespace std;

char base[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
char res[16];
int num;

//计算排列数A(x, y)
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
	//从高位往地位考虑
	for (curPos = 1; curPos <= 8; curPos++)
	{
		int curNum = 15;
		int countv;
		//一次遍历当前位所有可能的取值
		while (curNum >= 1)
		{
			if (!v[curNum])
			{
				//countv是当前位取curNum时,可以涵盖的数的个数
				if((countv=getAxy(16-1-useFulLen, 8-curPos))< num)
					num -= countv; //不可以涵盖,则num减去这个值
				else //可以涵盖
				{
					v[curNum] = true;
					break;
				}
			}
			curNum--;
		}
		res[curPos] = base[curNum];
		//要注意统计当前有效位的长度
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
