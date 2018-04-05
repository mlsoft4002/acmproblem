#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *next;
};
int main()
{
    int data,b,m,k,n,i;
    struct node *p,*q,*s,*h,*r;
    while(scanf("%d %d",&k,&n)!=EOF)
    {
        h=(struct node*)malloc(sizeof(struct node));
        q=h;
        for(i=0; i<n; i++)
        {
            scanf("%d",&data);
            s=(struct node*)malloc(sizeof(struct node));
            q->next=s;
            s->num=data;
            q=s;
        }
        q->next=NULL;
        q=h->next;
        for(m=0; m<n; m++)
        {
            if(m==n-k)//delete µ¹ÊýµÚk
            {
                s = q;
                p->next = q->next;
                q = q->next;
                free(s);
            }
            else
            {
                p=q;
                q=q->next;
            }
        }
        r=h->next;
        b=0;
        while(r!=NULL)
        {
            if(b==0)
                printf("%d",r->num);
            else
                printf(" %d",r->num);
            b++;
            r=r->next;
        }
        printf("\n");
        
        r=h;
        while(r!=NULL)
        {
            p = r;
            r = r->next;
            free(p);
        }
    }
    return 0;
}
