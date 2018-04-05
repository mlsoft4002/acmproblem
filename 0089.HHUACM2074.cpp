#include<iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
int look(string a)
{
    int i,l,j,s=0;
    l=a.length();
    for(i=0; i<l-2; i++)
    {
        if(a[i]=='T'&&a[i+1]=='O'&&a[i+2]=='J')s++;
    }
    for(i=l-1; i>=2; i--)
    {
        if(a[i]=='T'&&a[i-1]=='O'&&a[i-2]=='J')s++;
    }
    return s;
}
bool cmp(string a,string b)
{
    if(look(a)!=look(b))
        return look(a)>look(b);
    else
    {
        if(a.length()!=b.length())
            return a.length()>b.length();
        else return a>b;
    }
}
int main()
{
    int n,m;
    cin>>n;
    while(n--)
    {
        string a[1005];
        char s[1005];
        cin>>m;getchar();
        for(int j=0; j<m; j++)
        {
            gets(s);
            for(int i=0;s[i];i++)
                a[j]=a[j]+s[i];
        }
        sort(a,a+m,cmp);
        for(int i=0;i<m;i++)
            cout<<a[i]<<endl;
    }
    return 0;
}
