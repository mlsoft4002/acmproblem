#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define N 1000001
using namespace std;

string num;
int da[105], n, sizes;
int isprime[N+5];
int prime[N+5];

void shaixuan(int n)
{
    sizes = 0;
    memset(isprime,0,sizeof(isprime));
    int d = sqrt((double)n) + 1;
    for(int i = 2; i <= n; i++)
    {
        if(isprime[i])
            continue;
        prime[++sizes] = i;
        if(i > d)
            continue;
        for(int j = 2 * i; j <= n; j += i)
            isprime[j] = 1;
    }
}

int main()
{
    shaixuan(N);
    while(cin >> num >> n)
    {
        if(num[0] == '0' && n == 0)
            break;
        int k = 0, len = num.size(), sum = 0, xun = 0;
        for(int i = len - 1; i >= 0; i--)
        {
            int temp = num[i] - '0';
            for(int j = 1; j <= xun; j++)
                temp *= 10;
            sum += temp;
            xun++;
            if(xun == 3)
            {
                da[++k] = sum;
                sum = 0;
                xun = 0;
            }
        }
        if(sum != 0)
            da[++k] = sum;
        int flag = 0,ans;
        for(int i = 1; i <= sizes; i++)
        {
            int m = prime[i];
            if(m >= n) break;
            int ys = 0;
            for(int j = k; j >= 1; j--)
                ys = (ys * 1000 + da[j]) % m;
            if(ys == 0)
            {
                ans = m;
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<"BAD "<<ans<<endl;
        else
            cout<<"GOOD"<<endl;
    }
    return 0;
}
