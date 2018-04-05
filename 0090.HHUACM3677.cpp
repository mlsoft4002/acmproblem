#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
#include <map>
using namespace std;

char c[120005][25];
int leng;
map<string, int> m;
int main()
{
    int n = 0;
    while (gets(c[n]) != NULL)
    {
        m[c[n++]] = 1;
    }
    for (int i = 0; i < n ; i ++)
    {
        leng = strlen(c[i]);
        for (int j = 1; j < leng - 1; j ++)
        {
            char a[25], b[25];
            for (int k = 0; k < j; k ++)
                a[k] = c[i][k];
            a[j] = '\0';
            for (int k = j; k < leng; k ++)
                b[k-j] = c[i][k];
            b[leng-j] = '\0';
            if (m[a] == 1 && m[b] == 1)
            {
                printf("%s\n", c[i]);
                break;
            }
        }
    }
    return 0;
}
