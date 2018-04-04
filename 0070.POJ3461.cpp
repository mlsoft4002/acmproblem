#include<stdio.h>
#define M 1000010
char s[M],t[M];
int next[M],sum;
void getNext()//��next����
{
    int i,j;
    next[0]=-1;
    for(i=1,j=-1; s[i]; i++)
    {
        while(j!=-1&&s[i]!=s[j+1])j=next[j];
//��s[j+1]��ʼ����s[i]��ͬ����ĸ
        if(s[j+1]==s[i])j++;
        next[i]=j;//����ҵ���ͬ��ĸ��
//next[i]��¼��λ��,����next[i]=next[i-1]
    }
}
void kmp()
{
    int i,j;
    sum=0;
    getNext();
    for(i=0,j=-1; t[i]; i++)
    {
        while(j!=-1&&s[j+1]!=t[i])j=next[j];
//��next[j]�����ҳ���t[i]��ͬ��s[j+1]
        if(s[j+1]==t[i])j++;//����ҵ������ǰ��
        if(!s[j+1]) //�����t���ҵ�������s
        {
            sum++;//������1
            j=next[j];//��next����
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",s,t);
        kmp();
        printf("%d\n",sum);
    }
    return 0;
}
