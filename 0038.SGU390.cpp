#include <iostream>
using namespace std;

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#pragma comment (linker, "/STACK:1024000000,1024000000")

typedef long long ll;

const int maxn = 20;
const int maxk = 1010;

struct node
{
	ll cnt, rem;
	node(ll cnt = 0, ll rem = 0): cnt(cnt), rem(rem) {}
	node operator += (node nxt)
	{
		cnt += nxt.cnt;
		rem = nxt.rem;
		return *this;
	}
} dp[maxn][maxn * 10][maxk];

bool vis[maxn][maxn * 10][maxk];
int dl[maxn], dr[maxn];

ll l, r, k;

node dfs(int h, ll sum, ll rem, bool lim1, bool lim2)
{
	if (h == 0)
	{
		if (sum + rem >= k)
			return node(1, 0);
		return node(0, sum + rem);
	}
	if (vis[h][sum][rem] && !lim1 && !lim2)
		return dp[h][sum][rem];

	node ans(0, rem);
	int low = lim1 ? dl[h] : 0;
	int upp = lim2 ? dr[h] : 9;
	for (int i = low; i <= upp; i++)
		ans += dfs(h-1,sum+i,ans.rem,lim1&&i==low,lim2&&i==upp);
	if (!lim1 && !lim2)
	{
		dp[h][sum][rem] = ans;
		vis[h][sum][rem] = 1;
	}
	return ans;
}

int main()
{
	cin >> l >> r >> k;
	int cnt = 1;
	while (l)
	{
		dl[cnt++] = l % 10;
		l /= 10;
	}

	cnt = 1;
	while (r)
	{
		dr[cnt++] = r % 10;
		r /= 10;
	}

	node ans = dfs(cnt, 0, 0, 1, 1);
	cout << ans.cnt << endl;
	return 0;
}
