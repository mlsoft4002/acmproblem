#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
__int64 n;
int a[1000000];
struct node
{
    int x,y;
}s[1000000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int j=0,k=0;
       scanf("%I64d",&n);
       memset(a,0,sizeof(a));
       for(int i=2;i<=n;i++)
       {
           if(n%i==0)
           {
               n=n/i;
               a[i]++;
               i=i-1;
           }
       }
       for(int i=2;i<1000000;i++)
       {
           if(a[i]!=0)
            {
               s[k].x=i;
               s[k].y=a[i];
               k++;
            }
       }
       //if(k>=2)
       {
           printf("%d^%d",s[0].x,s[0].y);
           for(int i=1;i<k;i++)
           {
             printf("*%d^%d",s[i].x,s[i].y);
           }
       }
       printf("\n");
    }
    return 0;
}
