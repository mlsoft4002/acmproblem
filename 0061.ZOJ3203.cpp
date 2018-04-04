//三分法
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
const double eps = 1e-9;
double D, H, h;

double calc(double x)
{
    return D - x + H - (H - h) * D / x;
}

double solve(double l,double r)
{
    double mid, midmid;
    double d1, d2;
    do
    {
        mid = (l + r) / 2;
        midmid = (mid + r) / 2;
        d1 = calc(mid);
        d2 = calc(midmid);
        if(d1 >= d2)
            r = midmid;
        else
            l = mid;
    }while(r - l >= eps);
    return d1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&H,&h,&D);
        printf("%.3lf\n",solve((H-h)*D/H,D));
    }
    return 0;
}

//公式法
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    double H, h, D;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf %lf %lf",&H,&h,&D);
        double temp = sqrt((H - h) * D);
        double temp2 = (H - h) * D / H;
        if(temp >= D)
            printf("%.3lf\n",h);
        else if(temp < temp2)
            printf("%.3lf\n",h*D/H);
        else
        {
            double ans = D + H - temp - (H-h)*D/temp;
            printf("%.3lf\n",ans);
        }
    }
    return 0;
}
