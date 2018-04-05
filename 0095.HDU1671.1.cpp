#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char a[10005][11];
int cmp(const void *m,const void *n){
	return strcmp((char*)m,(char*)n);
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
	    qsort(a,n,sizeof(a[0]),cmp);
		bool flag=1;
		for(int i=0;i<n-1&&flag;i++){
			if(strncmp(a[i],a[i+1],strlen(a[i]))==0) flag=0;
		}
		if(flag) cout<<"YES";
		else     cout<<"NO";
		cout<<endl;
	}
}
