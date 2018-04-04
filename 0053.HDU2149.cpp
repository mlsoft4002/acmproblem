#include<stdio.h>
int main()
{
    int n, m;
    while(~scanf("%d %d",&n,&m))
    {
        if(m >= n){
            for(int i = n; i < m; i++)
                printf("%d ",i);
            printf("%d\n",m);
        }
        else{
            if(n % (m + 1) == 0)
                printf("none\n");
            else
                printf("%d\n",n % (m + 1));
        }
    }
    return 0;
}
