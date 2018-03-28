#include<iostream>
#include<cstdio>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y)
{
    long long d, t;
    if (b == 0) { x = 1; y = 0; return a; }
    d = exgcd(b, a % b, x, y);
    t = x - a/b*y; x = y; y = t;
    return d;
}

int main()
{
    long long a1,a2,r1,r2;
    long long a,b,c,x,y;
    int k;
    int i;
    while(scanf("%d",&k)!=EOF)
    {
        scanf("%lld%lld",&a1,&r1);
        int flag=1;
        for(i=1;i<k;i++)
        {
            scanf("%lld%lld",&a2,&r2);
            a=a1;
            b=a2;
            c=r2-r1;
            long long m=exgcd(a,b,x,y);
            if(c%m)
            {
                flag=0;
            }
            long long s=b/m;
            x=x*(c/m);
            x=(x%s+s)%s;
            r1=x*a1+r1;
            a1=a1*(a2/m);
        }
        if(flag)
        {
            cout<<r1<<endl;

        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
