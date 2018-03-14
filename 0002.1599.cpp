#include<iostream>
#include<string>
using namespace std;

int main(){
	string num[5];
	int i,maxlen,n,result,carry;
	cin>>n;
	while(n--){
		maxlen=0;
		carry=0;
		num[4]="";
		for(i=0;i<4;i++){
			cin>>num[i];
			if(num[i].length()>maxlen)
				maxlen=num[i].length();
		}
		maxlen++;
		for(i=0;i<5;i++){
			while(num[i].length()<maxlen)
				num[i]="0"+num[i];
		}
		for(i=maxlen-1;i>0;i--){	
			result=num[0][i]+num[1][i]+num[2][i]+num[3][i]-4*'0'+carry;
			num[4][i]=result%10+'0';
			carry=result/10;
		}
		num[4][0]=carry+'0';
		while(num[4][0]=='0' && num[4].length()>1)
			num[4].erase(0,1);
		cout<<num[4]<<endl;
	}
	return 0;
}