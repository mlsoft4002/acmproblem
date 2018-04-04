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
        //floor()函数:int floor(float number)取比浮点数小的最大整数
        int tmp = double(k * (1.0 + sqrt(5.0)) / 2.0);
        //只要判断temp是否等于a就行了,b=a+k,k不变,a满足,b就满足
        if(a == tmp)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
