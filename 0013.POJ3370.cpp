#include <cstdio>
#include <cstring>

#define maxn 1000005

int m[maxn], mod[maxn];

int main()
{
	int c, n, i, sum, len, pos;
	while (scanf("%d%d", &c, &n) && c + n){
		memset(mod, -1, sizeof(mod));
		for (i = sum = len = 0; i<n; i++){
			scanf("%d", &m[i]);
			if (len)continue;
			sum = (sum + m[i]) % c;
			if (sum == 0){
				pos = 0; len = i + 1;
			}
			else if (mod[sum] >= 0){
				pos = mod[sum] + 1;
				len = i - mod[sum];
			}
			else
				mod[sum] = i;
		}
		printf("%d", pos + 1);
		for (i = pos + 1; i<len + pos; i++)
			printf(" %d", i + 1);
		printf("/n");
	}
	return 0;
}
