#include<stdio.h>
#include<string.h>

int haha(int a, __int64 b){
	int sum = 1;
	while (b){
		if (b & 1)
			sum = (sum*a) % 100;
		a = (a*a) % 100;
		b = b >> 1;
	}
	return sum;
}

int main(){
	int T, i, temp;
	__int64 n;
	while (scanf("%d", &T) != EOF&&T){
		for (i = 1; i <= T; i++){
			scanf("%I64d", &n);
			printf("Case %d: ", i);
			if (n == 0)
				printf("%d\n", 1);
			else{
				temp = (haha(2, n - 1) + haha(4, n - 1)) % 100;
				printf("%d\n", temp);

			}
		}
		printf("\n");
	}
	return 0;
}
