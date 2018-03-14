 #include<stdio.h>
 #include<math.h>
 #include<string.h>
 #include<ctype.h>
 
 char a[2013],b[2013],c[2013],d[2013],L[2013];
 
 void solve()
 {
     int n,len,i,j,t,flag;
     int len1,len2,len3,len4;
     char *p,*q,*r,*s,*l;
     scanf("%d",&n);
     while(n--){
         scanf("%s",a);scanf("%s",b);scanf("%s",c);scanf("%s",d);
         len1=strlen(a);len2=strlen(b);len3=strlen(c);len4=strlen(d);
         p=strrev(a);q=strrev(b);r=strrev(c);s=strrev(d);
         i=t=flag=0;
         while(*p||*q||*r||*s){
             if(*p!='\0')  t+=*p-'0';
             if(*q!='\0')  t+=*q-'0';
             if(*r!='\0')  t+=*r-'0';
             if(*s!='\0')  t+=*s-'0';
             t+=flag;
             L[i++]=t%10+'0';
             flag=t/10;
             p++;q++;r++;s++;
             t=0;
             }
         if(flag) L[i]=flag+'0';
         len=strlen(L);
         l=strrev(L);
         printf("%s\n",l);
         memset(a,'\0',len1*sizeof(char));
         memset(b,'\0',len2*sizeof(char));
         memset(c,'\0',len3*sizeof(char));
         memset(d,'\0',len4*sizeof(char));
         memset(L,'\0',len*sizeof(char));
     }
 }
 
 int main()
 {
     solve();
     return 0;
 }