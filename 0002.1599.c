#include<stdio.h>
#include<string.h>
char a[2009],b[2009],c[2009],d[2009],L[2011];

int main()
{
    int n,len,i,j,t,flag;
    int len1,len2,len3,len4;
    char *p,*q,*r,*s,*l;
    scanf("%d",&n);
    while(n--){
        scanf("%s",a);scanf("%s",b);scanf("%s",c);scanf("%s",d);
        len1=strlen(a);len2=strlen(b);len3=strlen(c);len4=strlen(d);
        p=a+len1-1;q=b+len2-1;r=c+len3-1;s=d+len4-1;
        i=t=flag=0;
        while(p>=a||q>=b||r>=c||s>=d){
            if(p>=a)  t+=*p-'0'; 
            if(q>=b)  t+=*q-'0'; 
            if(r>=c)  t+=*r-'0';
            if(s>=d)  t+=*s-'0';
            t+=flag;
            L[i++]=t%10+'0';
            flag=t/10;
            p--;q--;r--;s--;
            t=0;
            }
        if(flag) L[i]=flag+'0';
        len=strlen(L);   l=strrev(L);
        printf("%s\n",l);
        memset(a,'\0',len1*sizeof(char));
        memset(b,'\0',len2*sizeof(char));
        memset(c,'\0',len3*sizeof(char));
        memset(d,'\0',len4*sizeof(char));
        memset(L,'\0',len*sizeof(char));
    }
    return 0;
}