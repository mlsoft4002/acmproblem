#include<stdio.h>
#include<string>
using namespace std;
char s[200005],ch;
int n,i,j,k;
int main()
{
  scanf("%d",&n);
  getchar();
  for (i=0;i<n;i++)
  {
    ch=getchar();
    if (ch>='a'&&ch<='z') s[i]=s[i+n]=ch;else i--;
  }
  i=0;j=1;
  while (j<=n)
  {
    for (k=0;k<n;k++)
      if (s[i+k]!=s[j+k]) break;
    if (s[i+k]==s[j+k]) break;
    if (s[i+k]<s[j+k]) j=j+k+1;else i=i+k+1;
    if (i==j) j++;
  }
  printf("%d\n",i);
  return 0;
}
