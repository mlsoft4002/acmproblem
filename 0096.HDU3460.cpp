#include <stdio.h>
#include <algorithm>
using namespace std;
struct data
{
    int sum;
    data *next[26];
    void Set()
    {
        sum=0;
        for(int i=0; i<26; i++)
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

void build(data *T,char *s)
{
    for(int i=0; s[i]; i++)
    {
        if(T->next[s[i]-'a']==NULL)
        {
            data *p=new data();
            p->Set();
            T->next[s[i]-'a']=p;
            T->next[s[i]-'a']->sum=T->sum+1;
            T=T->next[s[i]-'a'];
        }
        else
        {
            T=T->next[s[i]-'a'];
        }
    }
}//����

int sum;
int solve(data *T)
{
    sum++;
    for(int i=0; i<26; i++)
    {
        if(T->next[i]!=NULL)
        {
            T->sum=max(solve(T->next[i]),T->sum);
        }
    }
    return T->sum;
}

int main()
{
    int n;
    char s[60];
    data *root;

    while(~scanf("%d",&n))
    {
        sum=0;
        root=new data();
        root->Set();
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            build(root,s);
        }

        int temp=solve(root);
        // ��sum-1��*2 ���趼Ҫ��ӡ��ɾ��������
// n ��ӡ���� temp����Ҫɾ���� ������ӡ���Ǹ�
        printf("%d\n",(sum-1)*2+n-temp);
        Release(root);
    }
    return 0;
}
