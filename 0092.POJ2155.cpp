#include <stdio.h>
#include <string.h>

int a[1005][1005];
int n;
int Lowbit(int x)
{
    return x & (-x);
}
void updata(int x,int y)
{
    int i,k;
    for(i=x; i<=n; i+=Lowbit(i))
        for(k=y; k<=n; k+=Lowbit(k))
            a[i][k]++;
}
int GetSum(int x,int y)
{
    int i,k,sum = 0;
    for(i=x; i>0; i-=Lowbit(i))
        for(k=y; k>0; k-=Lowbit(k))
            sum += a[i][k];
    return sum;
}
int main()
{
    int cas,m;
    int x1,y1,x2,y2;
    char ch[2];
    scanf("%d",&cas);
    while( cas-- )
    {
        memset(a,0,sizeof(a));
        scanf("%d %d",&n,&m);
        while( m-- )
        {
            scanf("%s",ch);
            if( ch[0] == 'C' )
            {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                x1++;
                y1++;
                x2++;
                y2++;
                updata(x2,y2);
                updata(x1-1,y1-1);
                updata(x1-1,y2);
                updata(x2,y1-1);
            }
            else
            {
                scanf("%d %d",&x1,&y1);
                printf("%d\n",GetSum(x1,y1)%2);
            }
        }
        printf("\n");
    }
    return 0;
}
