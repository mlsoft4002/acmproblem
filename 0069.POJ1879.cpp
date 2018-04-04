#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
const int Max = 7005;
int mem[Max], mark[Max];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b,a%b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a,b);
}
void solve(int n)
{
    queue<int> q;
	 ///分别表示分钟指示器,5分钟指示器,时钟指示器
    stack<int> mins, f_mins, hours;
    for(int i = 0; i < n; i++)  ///将n入队,形成球队列
        q.push(i);
    for(int t = 0; t < 1440; t++)  ///对24小时,1440分钟进行枚举
    {
        int num = q.front();
        q.pop();
        if(mins.size() == 4) ///分钟指示器中已存在4个球
        {
            for(int i = 0; i < 4; i++)
            {
///将分钟指示器中的球按相反顺序放入球队列队尾
                q.push(mins.top());
                mins.pop();
            }
            if(f_mins.size() == 11) ///5分钟指示器中已存在11个球
            {
                for(int i = 0; i < 11; i++)
                {
///将5分钟指示器中的球按相反顺序放入球队列队尾
                    q.push(f_mins.top());
                    f_mins.pop();
                }
                if(hours.size() == 11) ///时钟指示器中已存在11个球
                {
                    for(int i = 0; i < 11; i++)
                    {
//将时钟指示器中的球按相反顺序放入球队列队尾
                        q.push(hours.top());
                        hours.pop();
                    }
//时钟指示器中的球等于12,则将入指示器的球放入队尾
                    q.push(num); 
                }
                else
                    hours.push(num);
            }else
                f_mins.push(num);
        }else
            mins.push(num);
    }
    for(int j = 0; j < n; j++)///存储球队列的状态
    {
        mem[j] = q.front();
        q.pop();
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        memset(mem,0,sizeof(mem));
        memset(mark,0,sizeof(mark));
        solve(n);
        int ans = 1;
///计算出循环节长度counts,并求最小公倍数
        for(int i = 0; i < n; i++) 
        {
            if(!mark[i])
            {
                mark[i] = 1; int j = mem[i]; int counts = 1;
                while(!mark[j])
                {
                    mark[j] = 1;
                    counts++;
                    j = mem[j];
                }
                ans = lcm(ans,counts);
            }
        }
        printf("%d balls cycle after %d days.\n",n,ans);
    }
    return 0;
}
