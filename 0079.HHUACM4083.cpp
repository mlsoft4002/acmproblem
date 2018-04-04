#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char a[10000];
    int kk,i;
    stack<char>sta;
    scanf("%d",&kk);
    while(kk--)
    {
        scanf("%s",a);
        for(i=0;a[i];i++)
        {
            if(sta.empty())
                sta.push(a[i]);
            else
            {
                if(a[i]==')'&&sta.top()=='(')
                    sta.pop();
                else if(a[i]=='}'&&sta.top()=='{')
                    sta.pop();
                else if(a[i]==']'&&sta.top()=='[')
                    sta.pop();
                else sta.push(a[i]);
            }
        }
        if(sta.empty())
            puts("YES");
        else 
puts("NO");
        while(!sta.empty())  sta.pop();
    }
    return 0;
}
