#include<stdio.h>
int main()
{
    int t, n, a[50], ans;
    int flag;
    scanf("%d",&t);
    while(t--)
    {
        flag = 1, ans = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i] != 1)
                flag=0;
            ans ^= a[i];
        }
        if(flag)
        {
            if(n&1)
                printf("Brother\n");
            else
                printf("John\n");
        }
        else
        {
            if(ans)
                printf("John\n");
            else
                printf("Brother\n");
        }
    }
    return 0;
}
