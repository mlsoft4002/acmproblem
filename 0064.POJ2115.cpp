#include<iostream>
using namespace std;

void exgcd(long long a,long long b,long long& d,long long& x,long long& y){//int& a 是定义一个存放整形变量a的地址
    if(!b){ d=a ; x=1 ; y=0; }              // d用来存储gcd(a,b)的值 
    else { exgcd(b , a%b , d , y , x); y -= x* (a/b); }
}

int main(){
    long long  A,B,C,d,x,y,T;
    int k ; 
    while(cin>>A>>B>>C>>k){
        if(A==0&&B==0&&C==0&&k==0)
             break;
        long long n = 1LL<<k; //n = 1 * 2^k ;注意此处,若为__int64,则应该是n = (__int64)1 << k;
        exgcd(C,n,d,x,y);           
        if( (B-A) % d != 0 ){
            cout<<"FOREVER\n";
        }
        else {
            x = x * (B-A) / d ;  
            T = n / d;
            x = ( x%T + T ) % T ;
            cout<<x<<endl;
        }
    } 
    return 0; 
}