#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int cas, n, i, j, k;
    string s[105];
    int flag, maxl, maxx;
    cin >> cas;
    while(cas--)
    {
        cin >> n;
        maxl=105;
        maxx = 0;
        for(i = 0; i < n; i++)
        {
            cin >> s[i];
            if(maxl > s[i].size())
            {
                flag = i;
                maxl = s[i].size();
            }
        }
        for(i = s[flag].size(); i > 0; i--)//������Ǵ��п�ʼ����
            for(j = 0; j < s[flag].size() - i + 1; j++)
            {
                string s1, s2;
                s1 = s[flag].substr(j, i);
//��j��ʼ ���ȡi���ַ����ظ�s1
                s2 = s1;
                reverse(s2.begin(), s2.end());//��ת����
                for(k = 0; k < n; k++)
                {
if(s[k].find(s1, 0) == 4294967295 
&& s[k].find(s2, 0) ==4294967295 ) 
//�������Ӵ���ĸ���ж�δ����ʱ������
                    {
                        break;//��Ϊ�Ҳ����ͻᷴ��4294967295 
//�ҵ��ᷴ�ص�һ��Ԫ�ص�λ��
                    }

                }

                if(k == n )
//��Ϊ����Ĵ���ʼ���̳��ȱ��� �����ҵ����������
                {
                    maxx = s1.size();
                    goto tt;
                }
            }
tt:
        cout << maxx << endl;
    }
    return 0;
}
