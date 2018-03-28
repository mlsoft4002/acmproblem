#include<stdio.h>

void EuclidGCD(longlong a,longlong b,longlong &d,longlong &x,longlong &y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
        return;
    }
    EuclidGCD(b,a%b,d,y,x);
    y=y-(a/b)*x;
}

int main()
{
    long long x,y,m,n,l;
    long long a,b,c,d,x1,y1;
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)!=EOF)
    {
        if(x!=y&&m==n)
        {
            printf("Pat/n");
            continue;
        }
        a=m-n;//ax+by=c
        b=l;
        c=y-x;
        if(a<0)//necessary,不需要改变b,因为y未知
        {
            a=-a;
            c=-c;
        }

        EuclidGCD(a,b,d,x1,y1);
//算出来的是ax+by=gcd(a,b) 中的x0,y0
        //printf("d==%lld/n",d);
        if(c%d!=0)
        {
            printf("Pat/n");
            continue;
        }
        x=x1*c/d;
        b=b/d;
        x=(x%b+b)%b;
        printf("%lld/n",x);
    }
    return 0;
}
