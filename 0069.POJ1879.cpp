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
	 ///�ֱ��ʾ����ָʾ��,5����ָʾ��,ʱ��ָʾ��
    stack<int> mins, f_mins, hours;
    for(int i = 0; i < n; i++)  ///��n���,�γ������
        q.push(i);
    for(int t = 0; t < 1440; t++)  ///��24Сʱ,1440���ӽ���ö��
    {
        int num = q.front();
        q.pop();
        if(mins.size() == 4) ///����ָʾ�����Ѵ���4����
        {
            for(int i = 0; i < 4; i++)
            {
///������ָʾ���е����෴˳���������ж�β
                q.push(mins.top());
                mins.pop();
            }
            if(f_mins.size() == 11) ///5����ָʾ�����Ѵ���11����
            {
                for(int i = 0; i < 11; i++)
                {
///��5����ָʾ���е����෴˳���������ж�β
                    q.push(f_mins.top());
                    f_mins.pop();
                }
                if(hours.size() == 11) ///ʱ��ָʾ�����Ѵ���11����
                {
                    for(int i = 0; i < 11; i++)
                    {
//��ʱ��ָʾ���е����෴˳���������ж�β
                        q.push(hours.top());
                        hours.pop();
                    }
//ʱ��ָʾ���е������12,����ָʾ����������β
                    q.push(num); 
                }
                else
                    hours.push(num);
            }else
                f_mins.push(num);
        }else
            mins.push(num);
    }
    for(int j = 0; j < n; j++)///�洢����е�״̬
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
///�����ѭ���ڳ���counts,������С������
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
