#include <stdio.h>
using namespace std;
int flag;

typedef struct data
{
    int  a;
    data *l;
    data *r;
}*tree;

void creat(tree &t,int e)
{
    if(!t)
    {
        t=new data;
        t->a=e;
        t->l=t->r=NULL;
        return;
    }
    if(e<t->a)
        creat(t->l,e);
    else creat(t->r,e);
}

void pre(tree t)
{
    if(!t)return;
    if(flag)printf(" ");
    printf("%d",t->a);
    flag++;
    pre(t->l);
    pre(t->r);
}
void mid(tree t)
{
    if(!t)return;
    mid(t->l);
    if(flag)printf(" ");
    printf("%d",t->a);
    flag++;
    mid(t->r);
}

void bac(tree t)
{
    if(!t)return;
    bac(t->l);
    bac(t->r);
    if(flag)printf(" ");
    printf("%d",t->a);
    flag++;
}

int main()
{
    tree t;
    int n,m,k;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        t=NULL;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&k);
            creat(t,k);
        }
        flag=0;
        pre(t);
        printf("\n");
        flag=0;
        mid(t);
        printf("\n");
        flag=0;
        bac(t);
        printf("\n");
    }
    return 0;
}
