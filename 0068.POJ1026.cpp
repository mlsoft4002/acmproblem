#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int num[205], mem[205];
char str[10000], ans[10000];

void solve(int z)///计算循环节长度
{
    for(int i = 1; i <= z; i++)
    {
        int j = num[i];
        int l = 1;
        while(i != j)
        {
            l++;
            j = num[j];
        }
        mem[i] = l;
    }
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        memset(mem,0,sizeof(mem));
        for(int i = 1; i <= n; i++)
            scanf("%d",&num[i]);
        solve(n);
        while(1)
        {
            int m;
            scanf("%d",&m);
            if(m == 0)  break;
            getchar();
            gets(str+1);
            int len = strlen(str+1);
            for(int i = len + 1; i <= n; i++)///补足字符串长度
                str[i] = ' ';
            str[n+1] = 0;
            for(int i = 1; i <= n; i++)
            {
                int k = i;
                for(int j = 0; j < m % mem[i]; j++)///对循环节其余
                    k = num[k];
                ans[k] = str[i];
            }
            ans[n+1] = 0;
            puts(ans+1);
        }
        printf("\n");
    }
    return 0;
}
