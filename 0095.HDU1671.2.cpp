#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    bool isstr;
    data *next[10];
    void Set()
    {
        isstr=false;
        for(int i=0;i<10;i++)
            next[i]=NULL;
    }//��ʼ
};
void Release(data *T)
{
    for(int i=0; i<10; i++)
        if(T->next[i]!=NULL)
            Release(T->next[i]);
    free(T);
}//�ͷ��ڴ�
int main()
{
    int n,cas;
    bool exist;
    char s[20];
    data *root,*temp,*t1;
    scanf("%d",&cas);
    while(cas--)
    {
        root=new data();
        root->Set();
        exist=true;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",s);
            if(exist)
            {
                temp=root;
                for(int i=0;s[i];i++)
                {
                    if(temp->next[s[i]-'0']==NULL)
                    {
                        t1=new data();
                        t1->Set();
                        temp->next[s[i]-'0']=t1;
                        temp=t1;
                    }//�����ھ�����
                    else
                    {
                        temp=temp->next[s[i]-'0'];
                        if(temp->isstr==true)
                        {
                            exist=false;
                        }
                        if(s[i+1]=='\0')
                        {
                            exist=false;
                        }
                    }//���ھ��ж��ǲ����Ѿ�����
                    if(s[i+1]=='\0')
                    {
                        temp->isstr=true;
                    }
                }
            }
        }
        if(exist)
            printf("YES\n");
        else printf("NO\n");
        Release(root);
    }
    return 0;
}
