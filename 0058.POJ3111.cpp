#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PEC 0.001

typedef struct
{
    int v,w,pos;
    double f;
}Mem;

Mem je[100000];

int cmp(const void *a,const void *b)
{
    Mem j1 =* (Mem *)a, j2 =* (Mem *)b;
    if(j1.f > j2.f)
        return -1;
    else if(j1.f<j2.f)
        return 1;
    return 0;
}

int main()
{
    int k, n, i, sv, sw;
    double p,res;
    scanf("%d%d",&n,&k);

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&je[i].v,&je[i].w);
        je[i].pos=i+1;
    }

    p=0.0;
    res=0.5;

    while(fabs(p - res) >= PEC)
    {
        p = res;
        sv = sw = 0;
        for(i = 0; i < n; i++)
            je[i].f = je[i].v - je[i].w * p;
        qsort(je,n,sizeof(je[0]),cmp);
        for(i = 0; i < k; i++)  {
            sv += je[i].v;
            sw += je[i].w;
        }
        res=(double)sv/sw;
    }
    for(i=0;i<k;i++)
    {
        printf("%d",je[i].pos);
        if(i < k - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
