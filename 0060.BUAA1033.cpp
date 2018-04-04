#include<iostream>
#include<stdio.h>
#include<math.h>
#define eps 1e-8
using namespace std;

typedef struct node
{
    double x, y, z;
}node;

node l, r, p;

double dist(node a,node b)//求a点到b点的距离
{
return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + 
(a.z-b.z)*(a.z-b.z));
}

int sgn(double a)
{
    return (a > eps) - (a < -eps);
}

node getmid(node a,node b)
{
    node mid;
    mid.x = (a.x + b.x) / 2;
    mid.y = (a.y + b.y) / 2;
    mid.z = (a.z + b.z) / 2;
    return mid;
}

node search()
{
    node mid, midmid;
    while(sgn(dist(l,r)) > 0)
    {
        mid = getmid(l,r);
        midmid = getmid(mid,r);
        if(dist(p,mid) < dist(p,midmid))
            r = midmid;
        else
            l = mid;
    }
    return r;
}

int main()
{
    int t;
    node k;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%lf %lf %lf",&p.x,&p.y,&p.z);
        scanf("%lf %lf %lf",&l.x,&l.y,&l.z);
        scanf("%lf %lf %lf",&r.x,&r.y,&r.z);
        k = search();
        printf("Case %d: %.2lf\n",i,dist(k,p));
    }
    return 0;
}
