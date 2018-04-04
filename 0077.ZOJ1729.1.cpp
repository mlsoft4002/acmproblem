#include <iostream>
#include <string>
using namespace std;

int solve(string str)
{
    string ss=str+str;//因为是环 *2一下就是线性数组了
    int i, j, k;
    i=k=0;
    j=1;
    //下面说i串 就是以i开头,i+len长度的串
    while(k<str.length()&&i<str.length()&&j<str.length())
    {
        if(ss[i+k]==ss[j+k])
        {
            k++;
        }
        else if(ss[i+k]>ss[j+k])//i串比j串大 i串就改变成别的串
        {
            i+=k+1;
            if(i==j)
                i++;
            k=0;
        }
        else//j比i小
        {
            j+=k+1;
            if(i==j)
                j++;
            k=0;
        }
    }
    //经过这个可以得出来最小的串开始 反回
    return i <j?i:j;
}

int main()
{
    string str,s;
    int u,n;
    while(cin>>n)
    {
        u=0;
        str="";
        while(u<n)
        {
            cin>>s;
            str+=s;
            u+=s.length();
        }//输入坑点
        cout<<solve(str)<<endl;
    }
    return 0;
}
