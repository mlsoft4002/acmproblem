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
        for(i = s[flag].size(); i > 0; i--)//用最短那串中开始遍历
            for(j = 0; j < s[flag].size() - i + 1; j++)
            {
                string s1, s2;
                s1 = s[flag].substr(j, i);
//从j开始 向后取i个字符反回给s1
                s2 = s1;
                reverse(s2.begin(), s2.end());//反转函数
                for(k = 0; k < n; k++)
                {
if(s[k].find(s1, 0) == 4294967295 
&& s[k].find(s2, 0) ==4294967295 ) 
//当正反子串在母串中都未发现时即跳出
                    {
                        break;//因为找不到就会反回4294967295 
//找到会反回第一个元素的位置
                    }

                }

                if(k == n )
//因为从最长的串开始减短长度遍历 所以找到就是最长的了
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
