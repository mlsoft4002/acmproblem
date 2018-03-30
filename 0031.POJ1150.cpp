#include<stdio.h>
#include<string.h>
#include<math.h>

int get2(int n){    //计算n!中质因子2的出现次数
	return n == 0 ? 0 : (n / 2 + get2(n / 2));
}

int get5(int n){    //计算n!中质因子5的出现次数
	return n == 0 ? 0 : (n / 5 + get5(n / 5));
}

int g(int n, int x){ 
//计算f(1) to f(n) 中，奇数数列中末尾为x的数出现的次数
	if (n == 0)
		return 0;
	return n / 10 + (n % 10 >= x) + g(n / 5, x);
}
int getx(int n, int x){      
//计算f(1) to f(n)中，末尾为x的数的出现次数
	if (n == 0)
		return 0;
	return getx(n / 2, x) + g(n, x);
}
int table[4][4] = {
	{ 6, 2, 4, 8 },  
//2^n%10的循环节，注意如果2的个数为0时候，结果应该是1，要特殊处理。
	{ 1, 3, 9, 7 },  //3
	{ 1, 7, 9, 3 },  //7
	{ 1, 9, 1, 9 }   //9
};//3，7，9的循环节中第一位，刚好是1，
//故不需要考虑这些数字出现次数为0的情况。
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF){
		int num2 = get2(n) - get2(n - m);
		int num5 = get5(n) - get5(n - m);
		int num3 = getx(n, 3) - getx(n - m, 3);
		int num7 = getx(n, 7) - getx(n - m, 7);
		int num9 = getx(n, 9) - getx(n - m, 9);
		int ans = 1;
		if (num5>num2){
			printf("5\n");
		}
		else{
			if (num2 != num5){
				ans *= table[0][(num2 - num5) % 4];
				ans %= 10;
			}       //如果num2==num5,那么2^0次方mod 10应该为1 ，
//而不是table中的6,所以要特殊处理。
			ans *= table[1][num3 % 4];
			ans %= 10;
			ans *= table[2][num7 % 4];
			ans %= 10;
			ans *= table[3][num9 % 4];
			ans %= 10;
			printf("%d\n", ans);
		}
	}
	return 0;
}
