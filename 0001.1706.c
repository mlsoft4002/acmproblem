// C����ʹ���ַ�����ʵ��,���´�����Microsoft Visual Studio 2013��ͨ����
#include<stdio.h>  
#include<string.h>  
int havepoint(char str[])  
{  
    int i,len;  
    len=strlen(str);  
    for(i=0;i<len;i++)  
    {  
        if(str[i]=='.')  
        return 1;  
    }  
    return 0;  
}  
void change(char str[])  
{  
    int i,len;  
    len=strlen(str);  
    if(havepoint(str))  
    {  
        for(i=len-1;str[i]=='0';i--)  //ȥ�������0
        {  
            str[i]='\0';  
            len--;  
        }  
        if(str[len-1]=='.')  //������һ���ǵ㣬��ȥ����
        str[len-1]='\0';  
    }  
    int mlen=0;
    for(i=0; str[i]=='0'&& !(str[i+1]=='\0'|| str[i+1]=='.');i++) mlen++;
    for(i=0; mlen>0&&i<len- mlen;i++) str[i]= str[i+mlen];
}  
int main()  
{  
    char str1[1000000],str2[1000000];  
    while(scanf("%s %s",str1,str2)!=EOF)  
    {  
        change(str1);  
        change(str2);  
        if(strcmp(str1,str2)==0)  
        printf("YES\n");  
        else printf("NO\n");  
    }  
    return 0;  
}  
