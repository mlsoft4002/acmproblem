#include<stdio.h>

unsigned long long mul(unsigned long long a,unsigned long long b,unsigned long long c)
{
	unsigned long long ret=0,tmp=a%c;
	while(b)
	{
		if(b&0x1)
			if((ret+=tmp)>=c)
				ret-=c;
			if((tmp<<=1)>=c)
				tmp-=c;
			b>>=1;
	} 
	return ret;
}

unsigned long long mod(unsigned long long a,unsigned long long b,unsigned long long c) 
{ 
   unsigned long long y=1; 
   while(b) 
   { 
      if(b&1) 
        y=mul(y,a,c); 
      a=mul(a,a,c); 
      b=b>>1; 
   } 
   return y; 
}

int main() 
{ 
   unsigned long long a,b,c; 
   while(scanf("%llu%llu%llu",&a,&b,&c)!=EOF)
       printf("%llu/n",mod(a,b,c)); 
   return 0; 
}
