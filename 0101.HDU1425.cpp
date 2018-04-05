#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
bool isExist[1000001];
int main(){
    int n, m, a;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(isExist,false,sizeof(isExist));
        while(n--){
            scanf("%d",&a);
            isExist[a+500000] = true;
        }
        a = 1000000;
        while(m--){
            while(!isExist[a])a--;
            printf("%d",a-500000);
            a--;
            if(m>0) putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
