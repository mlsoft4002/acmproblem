#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<memory.h>
using namespace std;
const int N=50000;
long prime[N]={0},num_prime=0;
int isNotPrime[N]={1,1};
int dis[1000010];
void sushu()
{
    for(long i=2;i<N;i++)
    {
        if(!isNotPrime[i])
        prime[num_prime++]=i;
        for(long j=0;j<num_prime&&i*prime[j]<N;j++)
        {
            isNotPrime[i*prime[j]]=1;
            if(!(i%prime[j]))
            break;
        }
    }
}
int main()
{
    long long  l,u;
    sushu();
    while(scanf("%lld%lld",&l,&u)!=EOF)
    {
       for(long long  i=l;i<=u;i++)
       dis[i-l]=0;//假设一开始[l,u]全是素数
//利用素数筛选的原理，用已知的素数把[l,u]之间一些数筛掉
       for(int i=0;i<num_prime;i++) 
       {
           long long  j=l/prime[i];
           if(j*prime[i]>u) break;
           if(l%prime[i]) j++;
           if(j==1) j++;
           for(;j*prime[i]<=u;j++)//素数的倍数落在[l,u]这个区间的要筛掉
           {
               dis[j*prime[i]-l]=1;
              //cout<<(j*prime[i]-l)<<"&"<<endl;
           }
       }
       long long  pi;
       for(long long  i=l;i<=u;i++)
       {
           if(!dis[i-l])
           {
               pi=i;
               break;
           }
       }
       if(pi==1)
       pi++;
       //cout<<pi<<endl;
       long long  m1,m2,n1,n2;
       int minn=1000001;
       int maxn=-1;
       for(long long  i=pi+1;i<=u;i++)
       {
           if(!dis[i-l])
           {
               int f=i-pi;
               if(f<minn)
               {
                  minn=f;
                  m1=pi;
                  m2=i;
               }
               if(f>maxn)
               {
                   maxn=f;
                   n1=pi;
                   n2=i;
               }
               pi=i;
           }
       }
       if(minn!=1000001&&maxn!=-1)
       {
           printf("%lld,%lld are closest",m1,m2);
               printf(", %lld,%lld are most distant.\n",n1,n2);
       }
       else
           printf("There are no adjacent primes.\n");
    }
}
