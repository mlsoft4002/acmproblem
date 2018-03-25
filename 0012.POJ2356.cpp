#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=11000;
int n,a[maxn],sum[maxn],visited[maxn];
void solve(){
    for(int i=1;i<=n;i++){
        if(sum[i]%n==0){
            printf("%d\n",i);
            for(int t=1;t<=i;t++){
                printf("%d\n",a[t]);
            }
            return ;
        }
    }
    for(int i=0;i<=n;i++) visited[i]=-1;
    for(int i=1;i<=n;i++){
        if(visited[sum[i]%n]!=-1){
            int t=visited[sum[i]%n];
            printf("%d\n",i-t);
            for(t=t+1;t<=i;t++){
                printf("%d\n",a[t]);
            }
        }else{
            visited[sum[i]%n]=i;
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sum[0]=0;
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        solve();
    }
    return 0;
}
