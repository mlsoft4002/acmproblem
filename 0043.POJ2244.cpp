#include<stdio.h>
#include<string.h>

int f[152], ans[152];

void Init(){
	int m, i, j, count = 0, flag = 0;
	memset(f, 0, sizeof(f)); f[1] = 0;
	for (i = 2; i<150; i++){
		for (m = 2;; m++){
			for (j = 2; j <= i; j++)
				f[j] = (f[j - 1] + m) % j; //j,当前人数； 
			if (f[i] == 0){ ans[i + 1] = m; break; }
		}
	}
}

int main()
{
	int k;
	Init();
	while (scanf("%d", &k), k)
		printf("%d/n", ans[k]);
}
