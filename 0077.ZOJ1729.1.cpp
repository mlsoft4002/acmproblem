#include <iostream>
#include <string>
using namespace std;

int solve(string str)
{
    string ss=str+str;//��Ϊ�ǻ� *2һ�¾�������������
    int i, j, k;
    i=k=0;
    j=1;
    //����˵i�� ������i��ͷ,i+len���ȵĴ�
    while(k<str.length()&&i<str.length()&&j<str.length())
    {
        if(ss[i+k]==ss[j+k])
        {
            k++;
        }
        else if(ss[i+k]>ss[j+k])//i����j���� i���͸ı�ɱ�Ĵ�
        {
            i+=k+1;
            if(i==j)
                i++;
            k=0;
        }
        else//j��iС
        {
            j+=k+1;
            if(i==j)
                j++;
            k=0;
        }
    }
    //����������Եó�����С�Ĵ���ʼ ����
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
        }//����ӵ�
        cout<<solve(str)<<endl;
    }
    return 0;
}
