#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int zheng[1000001];//保留非负数的结果
int fu[1000001]; //保留负数的结果
int main(){
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
        if(a>0 && b>0 && c>0 && d>0){
            printf("0\n");continue;
        }
        memset(zheng,0,sizeof(zheng));
        memset(fu,0,sizeof(fu));
        for(int x1=1; x1<=100; x1++){
            for(int x2=1; x2<=100; x2++){
                int temp = a*x1*x1+b*x2*x2;
                if(temp>=0){
                    zheng[temp]++;
                }else{
                    fu[-temp]++;
                }
            }
        }
        int ans = 0;
        for(int x3=1; x3<=100; x3++){
            for(int x4=1; x4<=100; x4++){
                int temp = c*x3*x3+d*x4*x4;
                if(temp>0){//需要负的抵消
                    ans += fu[temp];
                }else{
                    ans += zheng[-temp];
                }
            }
        }
        printf("%d\n",ans*16);
    }
    return 0;
}
