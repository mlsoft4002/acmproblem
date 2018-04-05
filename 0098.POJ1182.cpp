#include <iostream>
#include <stdio.h>
using namespace std;
int date[50001*3];
void init(int n){
    for(int i=0; i<=3*n; i++)date[i] = i;
}
int find_root(int index){
    if(date[index]==index)return index;
    return date[index] = find_root(date[index]);
}
void union_set(int a,int b){
    int r1 = find_root(a);
    int r2 = find_root(b);
    if(r1!=r2){
        date[r1] = r2;
    }
}
//判断是否在一个集合
bool isInOneSet(int a,int b){
    return find_root(a)==find_root(b);
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    //初始化并查集
    init(n);
    int sc, x, y;
    int ans = 0;

    while(k--){
        scanf("%d%d%d",&sc,&x,&y);
        //x,y不在范围内
        if(x<1 || x>n || y<1 || y>n){
            ans++;continue;
        }

        //自己吃自己
        if(sc==2 && x==y){
             ans++;continue;
        }

        if(sc==1){//同类关系
            //x，y之间有吃与被吃的关系
            if(isInOneSet(x,n+y) || isInOneSet(x,2*n+y)){
                ans++;
            }else{
                //插入正确记录
                union_set(x,y);
                union_set(n+x,n+y);
                union_set(2*n+x,2*n+y);
            }
        }else if(sc==2){
            //不能(与x吃y)有冲突关系(y吃x)，
//包括同类和吃的顺序,把x,y看做分析中的a,b
            if(isInOneSet(x,y) || isInOneSet(x,n+y)){
                ans++;
            }else{
                  //插入正确记录
                union_set(x,2*n+y);
                union_set(n+x,y);
                union_set(2*n+x,n+y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
