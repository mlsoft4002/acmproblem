#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int Max = 1005;
int num[Max], mark[Max], ans[Max];

int solve(int n)
{
    int len = 0;
    while(1)
    {
        for(int i = 1; i <= n; i++)
            mark[i] = num[num[i]];
        len++;
        bool flag = true;
        for(int i = 1; i <= n; i++)
        {
            if(mark[i] != ans[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            break;
        for(int i = 1; i <= n; i++)
            num[i] = mark[i];
    }
    return len;
}

int main()
{
    int n, s;
    while(~scanf("%d %d",&n,&s))
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&num[i]);
            ans[i] = num[i];
        }
        int len;
        len = solve(n);
        s = s % len;
        len = len - s;
        for(int i = 1; i <= n; i++)
            num[i] = mark[i];
        while(len--)
        {
            for(int i = 1; i <= n; i++)
                mark[i] = num[num[i]];
            for(int i = 1; i <= n; i++)
                num[i] = mark[i];
        }
        for(int i = 1; i <= n; i++)
            printf("%d\n",num[i]);
    }
    return 0;
}
