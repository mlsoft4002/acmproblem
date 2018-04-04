#include<stdio.h>
#define M 1000010
char s[M],t[M];
int next[M],sum;
void getNext()//求next数组
{
    int i,j;
    next[0]=-1;
    for(i=1,j=-1; s[i]; i++)
    {
        while(j!=-1&&s[i]!=s[j+1])j=next[j];
//从s[j+1]开始找与s[i]相同的字母
        if(s[j+1]==s[i])j++;
        next[i]=j;//如果找到相同字母，
//next[i]记录此位置,否则next[i]=next[i-1]
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
//按next[j]后退找出与t[i]相同的s[j+1]
        if(s[j+1]==t[i])j++;//如果找到则向后前进
        if(!s[j+1]) //如果在t中找到完整的s
        {
            sum++;//计数增1
            j=next[j];//按next后退
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
