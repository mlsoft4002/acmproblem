#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int a, b;
    while(~scanf("%d %d",&a,&b))
    {
        if(a > b)   swap(a,b);
        int k = b - a;
        //floor()����:int floor(float number)ȡ�ȸ�����С���������
        int tmp = double(k * (1.0 + sqrt(5.0)) / 2.0);
        //ֻҪ�ж�temp�Ƿ����a������,b=a+k,k����,a����,b������
        if(a == tmp)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
