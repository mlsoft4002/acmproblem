#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100000 + 5;

int a[N];

int mn[N][25];

int n, q, l, r;

struct RMQ{
    int log2[N];
    void init(){
        for(int i=0; i<=n; i++) log2[i]=(i==0?-1:log2[i >> 1] + 1);
        for(int j = 1; j < 20; j ++)
            for(int i = 1; i + (1 << j) <= n + 1; i ++)
                mn[i][j]=min(mn[i][j-1], mn[i + (1<<j-1)][j-1]);
    }
    int query(int ql, int qr){
        int k = log2[qr - ql + 1];
        return min(mn[ql][k], mn[qr - (1 << k) + 1][k]);
    }
}rmq;

void work(){
    rmq.init();
    scanf("%d", &q);
    while(q --){
        scanf("%d%d", &l, &r);
        printf("%d\n", rmq.query(l, r));
    }
}

int main(){
    while(scanf("%d", &n) == 1){
        for(int i = 1; i <= n; i ++)scanf("%d", a + i), mn[i][0] = a[i];
        work();
    }
    return 0;
}
