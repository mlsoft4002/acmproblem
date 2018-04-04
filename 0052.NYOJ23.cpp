#include <stdio.h>
int main()
{
    int n, m, z;
    scanf("%d",&z);
    while(z--)
    {
        scanf("%d %d",&n,&m);
        printf(n%(m+1) ? "Win\n" : "Lose\n");
    }
    return 0;
}
