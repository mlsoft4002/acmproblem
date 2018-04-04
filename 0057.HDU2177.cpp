#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double x = (1 + sqrt(5.0)) / 2.0;
    int a, b;
    while(~scanf("%d%d",&a,&b) && (a+b))
    {
        int k, n, m;
        if(a > b)
            swap(a,b);
        k = b - a;
        //判断是否为奇异状态，若为奇异状态，则先者必败
        if((int)(k * x) == a)
            printf("%d\n",0);
        else
        {
            printf("%d\n",1);
            //先暴力从两堆中一起拿的情况
            for(int i = 1; i <= a; i++)
            {
                n = a - i;
                m = b - i;
                k = m - n;
                if((int)(k * x) == n)
                    printf("%d %d\n",n,m);
            }
            //再暴力从一个中拿走的情况，
            for(int i = b - 1; i >= 0; i--)
            {
                n = a;  m = i;
                if(n > m)
                    swap(n,m);
                k = m - n;
                if((int)(k * x) == n)
                    printf("%d %d\n",n,m);
            }
        }
    }
    return 0;
}
