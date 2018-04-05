#include <stdio.h>
#include <string.h>
int a[100005];
int n;
int LowBit(int x)
{
    return x & (-x);}
void add(int x, int sum)
{
    while (x <= n)
    {
        a[x] += sum;
        x += LowBit(x);
    }
}
int GetSum(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += a[x];
        x -= LowBit(x);
    }
    return ans;
}
int main()
{
    int A, B;
    while (scanf("%d", &n), n){
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++i){
            scanf("%d%d", &A, &B);
            add(A, 1);
            add(B + 1, -1);
        }
        for (int i = 1; i <n; ++i){
            printf("%d ", GetSum(i));
}
        printf("%d\n", GetSum(n));
    }
    return 0;
}
