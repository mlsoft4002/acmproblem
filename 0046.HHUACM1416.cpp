//以下代码在Microsoft Visual Studio 2013中通过。
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<cstdlib>

int aliquotDivisorSum(const int n){
	if (n <= 1){
		return 0;
	}
	else{
		int sum = 1;						//1是任何大于2的数的真因子
		for (int i = 2; i < n; ++i){
			if (n%i == 0) sum += i;
		}
		return sum;
	}
}

int main(void){
	int k;
	cin >> k;
	while (k--){
		int a, b;
		cin >> a >> b;
if(aliquotDivisorSum(a) == b && aliquotDivisorSum(b) == a)
			puts("YES");
else 
puts("NO ");
	}
	return EXIT_SUCCESS;
}
