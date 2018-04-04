#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char a[205];
    double temp,x,y;
    while(gets(a))
    {
        if(!strcmp("0",a))
            break;

        stack<double>num;//存数字
        stack<char>ch;//存符号
        for(int i=0; a[i]; i++)
        {
            if(a[i]==' ')
                continue;
            else if(a[i]>='0'&&a[i]<='9')//将数字取出来
            {
                temp=0;
                while(a[i]>='0'&&a[i]<='9')
                {
                    temp=temp*10+a[i]-'0';
                    i++;
                }
                num.push(temp);
                i--;
            }
            Else
            {
                if(ch.empty())
                    ch.push(a[i]);//如果之前没有保存字符，
//即之前数字不足两个不用再考虑下面的运算
                else
                {
                    if(a[i]=='+'||a[i]=='-')
                    {
                        while(!ch.empty())
                        {
                            x=num.top();
                            num.pop();
                            y=num.top();
                            num.pop();
                            if (ch.top()=='*') num.push(y*x);
                            if (ch.top()=='/') num.push(y/x);
                            if (ch.top()=='+') num.push(y+x);
                            if (ch.top()=='-') num.push(y-x);
                            ch.pop();
                        }
                    }
                    else if(ch.top()=='*'|| ch.top()=='/')
                    {
                        x=num.top();
                        num.pop();
                        y=num.top();
                        num.pop();
                        if (ch.top()=='*') num.push(y*x);
                        if (ch.top()=='/') num.push(y/x);
                        if (ch.top()=='+') num.push(y+x);
                        if (ch.top()=='-') num.push(y-x);
                        ch.pop();
                    }
                    ch.push(a[i]);
                }
            }
        }
        while(!ch.empty())
        {
            x=num.top();
            num.pop();
            y=num.top();
            num.pop();
            if (ch.top()=='*') num.push(y*x);
            if (ch.top()=='/') num.push(y/x);
            if (ch.top()=='+') num.push(y+x);
            if (ch.top()=='-') num.push(y-x);
            ch.pop();
        }
        printf("%.2lf\n",num.top());
    }
    return 0;
}
