#include <stdio.h>
#include <string.h>

int n, k, m;

int main() {
	while (~scanf("%d%d%d", &n, &k, &m) && n + k + m) {
		int ans = 0;
		for (int i = 2; i <= n - 1; i++)
			ans = (ans + k) % i;
		printf("%d\n", (ans + m) % n + 1);
	}
	return 0;
}
