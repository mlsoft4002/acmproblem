#include<iostream>
using namespace std;

void exgcd(long long a,long long b,long long& d,long long& x,long long& y){//int& a �Ƕ���һ��������α���a�ĵ�ַ
    if(!b){ d=a ; x=1 ; y=0; }              // d�����洢gcd(a,b)��ֵ 
    else { exgcd(b , a%b , d , y , x); y -= x* (a/b); }
}

int main(){
    long long  A,B,C,d,x,y,T;
    int k ; 
    while(cin>>A>>B>>C>>k){
        if(A==0&&B==0&&C==0&&k==0)
             break;
        long long n = 1LL<<k; //n = 1 * 2^k ;ע��˴�,��Ϊ__int64,��Ӧ����n = (__int64)1 << k;
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