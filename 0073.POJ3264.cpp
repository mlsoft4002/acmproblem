#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n,q;

int A[50001];
int mx[50001][20],mm[50001][20];
int max(int a,int b)
{
    return  a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
void rmq_init()
{
    int i,j,k,m;
    m=(int)(log(n)/log(2.0));
    for(i=1; i<=n; i++)
    {
        mx[i][0]=mm[i][0]=A[i];
    }
    for(j=1; j<=m; j++)
    {
        for(i=1; i<=n; i++)
        {
            mx[i][j]=mx[i][j-1];
            k=1<<(j-1);
            if(i+k<=n)
                mx[i][j]=max(mx[i][j],mx[i+k][j-1]);
        }
    }
    for(j=1; j<=m; j++)
    {
        for(i=1; i<=n; i++)
        {
            mm[i][j]=mm[i][j-1];
            k=1<<(j-1);
            if(i+k<=n)
                mm[i][j]=min(mm[i][j],mm[i+k][j-1]);
        }
    }
}
int rmq_query(int l,int r)
{
    int i,j,m;
    m=(int)(log(r-l+1)/log(2.0));
    i=max(mx[l][m],mx[r-(1<<m)+1][m]);
    j=min(mm[l][m],mm[r-(1<<m)+1][m]);
    return i-j;
}
int main()
{
    int i,j,k,m;
    scanf("%d%d",&n,&q);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&A[i]);
    }
    rmq_init();
    for(i=1; i<=q; i++)
    {
        scanf("%d%d",&j,&k);
        printf("%d\n",rmq_query(j,k));
    }
    return 0;
}
