#include<iostream>
using namespace std;
const int N = 1005;
int f[N];
int main()
{
	int i, j, co, n;
	memset(f, 0, sizeof(f));
	co = 1;
	for (i=2; i<=N; i++)
	{
		if (f[i]==0)
		{
			for (j=i; j<=N; j+=i) 
			f[j] = co;
			co++;
		}
	}
	while (scanf("%d", &n)!=EOF)
	{
		printf("%d\n", f[n]);
	}
	return 0;
}
