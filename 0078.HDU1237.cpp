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

        stack<double>num;//������
        stack<char>ch;//�����
        for(int i=0; a[i]; i++)
        {
            if(a[i]==' ')
                continue;
            else if(a[i]>='0'&&a[i]<='9')//������ȡ����
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
                    ch.push(a[i]);//���֮ǰû�б����ַ���
//��֮ǰ���ֲ������������ٿ������������
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
