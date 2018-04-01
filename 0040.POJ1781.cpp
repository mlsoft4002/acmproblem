#include <stdio.h>
#include <string.h>

int p[30];
int main() {
	for (int i = 0; i <= 27; i++) 
		p[i] = 1 << i;
	char s[10];
	int i;
	while (~scanf("%s", s))
	{
		if (strcmp(s, "00e0") == 0)
			break;
		int n;
		n = (s[0] - '0') * 10 + s[1] - '0';
		for (i = 1; i <= s[3] - '0'; i++)
			n = n * 10;
		for (i = 0; i <= 27; i++){
			if (p[i] >= n)
				break;
			if (p[i] == n)
				printf("1n");
			else
				printf("%dn", (n - p[i - 1]) * 2 + 1);
		}
	}
	return 0;
}
