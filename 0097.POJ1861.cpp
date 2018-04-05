#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct node{
    int x, y, w;
}g[15010];
int sc[15010], lsc;
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int father[15010];
int find_set(int x){
    if(father[x] == x) return x;
    return father[x] = find_set(father[x]);
}
void union_set(int x,int y){
    x = find_set(x);
    y = find_set(y);
    father[x] = y;
}
int main()
{
    int n, m, i, x, y, maxw;
    while( scanf("%d%d", &n, &m)!=EOF ){
        for(i = 1; i <= m; i++ ){
            scanf("%d%d%d", &g[i].x, &g[i].y, &g[i].w);
            father[i] = i; //自己和自己在一个集合
        }
        sort(g+1, g+m+1, cmp);
        maxw = lsc = 0;
        for(i = 1; i <= m; i++ ){
            x = find_set(g[i].x);
            y = find_set(g[i].y);
            if(x!=y){    //不在一个集合就放在一起
                union_set(x, y);
                sc[lsc++] = i;
                maxw = maxw < g[i].w ? g[i].w : maxw;
            }
        }
        printf("%d\n", maxw);
        printf("%d\n", lsc);
        for(i = 0; i < lsc; i++){
            printf("%d %d\n", g[sc[i]].x, g[sc[i]].y);
        }
    }
}
