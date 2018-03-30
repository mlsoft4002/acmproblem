#include<stdio.h>
#include<string.h>
#include<math.h>

int get2(int n){    //����n!��������2�ĳ��ִ���
	return n == 0 ? 0 : (n / 2 + get2(n / 2));
}

int get5(int n){    //����n!��������5�ĳ��ִ���
	return n == 0 ? 0 : (n / 5 + get5(n / 5));
}

int g(int n, int x){ 
//����f(1) to f(n) �У�����������ĩβΪx�������ֵĴ���
	if (n == 0)
		return 0;
	return n / 10 + (n % 10 >= x) + g(n / 5, x);
}
int getx(int n, int x){      
//����f(1) to f(n)�У�ĩβΪx�����ĳ��ִ���
	if (n == 0)
		return 0;
	return getx(n / 2, x) + g(n, x);
}
int table[4][4] = {
	{ 6, 2, 4, 8 },  
//2^n%10��ѭ���ڣ�ע�����2�ĸ���Ϊ0ʱ�򣬽��Ӧ����1��Ҫ���⴦��
	{ 1, 3, 9, 7 },  //3
	{ 1, 7, 9, 3 },  //7
	{ 1, 9, 1, 9 }   //9
};//3��7��9��ѭ�����е�һλ���պ���1��
//�ʲ���Ҫ������Щ���ֳ��ִ���Ϊ0�������
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
			}       //���num2==num5,��ô2^0�η�mod 10Ӧ��Ϊ1 ��
//������table�е�6,����Ҫ���⴦��
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
