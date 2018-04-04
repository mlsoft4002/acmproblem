#include<stdio.h>
using namespace std;
int main()
{
    int i, n, m;
    while(~scanf("%d",&n))
    {
        int flag = 0; //ÅÐ¶ÏÊÇ·ñÊÇ¹Âµ¥¶Ñ
        int s = 0;
        for(i = 0;i < n;i++)
        {
            scanf("%d",&m);
            s ^= m;
            if(m > 1)
                flag = 1;
        }
        if(flag == 0)
        {
            if(n % 2)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else
        {
            if(s == 0)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}
