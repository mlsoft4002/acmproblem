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
        //�ж��Ƿ�Ϊ����״̬����Ϊ����״̬�������߱ذ�
        if((int)(k * x) == a)
            printf("%d\n",0);
        else
        {
            printf("%d\n",1);
            //�ȱ�����������һ���õ����
            for(int i = 1; i <= a; i++)
            {
                n = a - i;
                m = b - i;
                k = m - n;
                if((int)(k * x) == n)
                    printf("%d %d\n",n,m);
            }
            //�ٱ�����һ�������ߵ������
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
