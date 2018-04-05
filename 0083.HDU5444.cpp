#include <stdio.h>
#include <iostream>
#include <queue>
#include <math.h>
#include <string.h>
#include <map>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <set>
#include <algorithm>
using namespace std;

struct p
{
    struct p *l,*r;
    int data;
    void init()
    {
        l=NULL;
        r=NULL;
    }
};
void in(struct p *root,struct p *q)
{
    if(root->data<q->data)
    {
        if(root->l==NULL)
            root->l=q;
        else in(root->l,q);
    }
    else if(root->data>q->data)
    {
        if(root->r==NULL)
            root->r=q;
        else in(root->r,q);
    }
}
void findd(struct p *root,int data)
{
    if(data==root->data)
    {
        return ;
    }
    if(data>root->data)
    {
        printf("W");
        findd(root->l,data);
    }
    else if(data<root->data)
    {
        printf("E");
        findd(root->r,data);
    }
}
void fre(struct p *root)
{
    if(root->l!=NULL)
        fre(root->l);
    if(root->r!=NULL)
        fre(root->r);
    delete root;
}
int main()
{
    int flag,cas;
    scanf("%d",&cas);
    while(cas--)
    {
        p *root,*q;
        int n,m;
        scanf("%d",&n);
        scanf("%d",&m);
        root=new p;
        root->init();
        root->data=m;
        for(int i=1; i<n; i++)
        {
            scanf("%d",&m);
            q=new p;
            q->init();
            q->data=m;
            in(root,q);
        }
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&m);
            findd(root,m);
            printf("\n");
        }
        fre(root);
    }
    return 0;
}
