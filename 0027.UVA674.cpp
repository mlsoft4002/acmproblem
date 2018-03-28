#include<stdio.h>
#include<string.h>

int c1[252][102], c2[252][102];
int a[6] = { 0, 1, 5, 10, 25, 50 };

int main(void){
	int n;
	while (~scanf("%d", &n)){
		if (n == 0){
			printf("1\n");
			continue;
		}
		int sum = 0;
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		int i, j, k, l;
		for (i = 0; i <= 100; ++i){
			c1[i][i] = 1;
		}
		for (i = 2; i <= 5; ++i){
			for (j = 0; j <= n; ++j){
				for (k = 0; k + j <= n; k += a[i]){
					for (l = 0; l + k / a[i] <= 100; l++)
						c2[j + k][l + k / a[i]] += c1[j][l];
				}
			}
			for (j = 0; j <= n; ++j){
				for (k = 0; k <= 100; ++k){
					c1[j][k] = c2[j][k];
					c2[j][k] = 0;
				}
			}
		}
		for (i = 0; i <= 100; ++i)
			sum += c1[n][i];
		printf("%d\n", sum);
	}
	return 0;
}
