#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int son;
	int distance;
};

int n;
vector<node>v[40001];//存儿子标号
int deep[40001];//每个点的深度
int visitnum[80001];//遍历数是2*n-1
int visitn[40001];//每个点的任意一个遍历数
int vnum;
int mins[80001][18];		//区间最小值
int dist[40001];		//每个点到祖先的距离distance
int fa[40001];

void visit(int m, int d, int dis)		//遍历重编号、计算distance
{
	vector<node>::iterator p;
	deep[m] = d;
	dist[m] = dis;
	for (p = v[m].begin(); p != v[m].end(); p++)
	{
		if (fa[(*p).son]>-1)continue;
		fa[(*p).son] = m;
		visitnum[vnum++] = m;	//存入访问的第vnum个点是哪个点
		visit((*p).son, d + 1, dis + (*p).distance);
	}
	visitn[m] = vnum;		//注意这2句的顺序
	visitnum[vnum++] = m;
}

void rmq()		//计算区间最小值
{
	for (int i = 1; i <= 2 * n - 1; i++)mins[i][0] = visitnum[i];
	for (int j = 1; (1 << j) <= 2 * n - 1; j++)
	{
		for (int i = 1; i <= 2 * n - 1; i++)
		{
			mins[i][j] = mins[i][j - 1];
			int k = i + (1 << (j - 1));
			if (k <= 2 * n - 1 && deep[mins[i][j]] > deep[mins[k][j - 1]])
				mins[i][j] = mins[k][j - 1];
		}
	}
}

int lca(int x, int y)	//求最近公共祖先
{
	x = visitn[x], y = visitn[y];
	if (x > y)x ^= y ^= x ^= y;
	int j = 0;
	while ((1 << j) <= y - x + 1)j++;
	j--;
	int min = mins[y + 1 - (1 << j)][j];
	if (deep[min] > deep[mins[x][j]])min = mins[x][j];
	return min;
}

int main()
{
	int t, m, x, y, l;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vnum = 1;
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();	//初始化
			fa[i] = -1;
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d%d", &x, &y, &l);
			node nod1, nod2;
			nod1.distance = l, nod1.son = y;
			v[x].insert(v[x].end(), nod1);
			nod2.distance = l, nod2.son = x;
			v[y].insert(v[y].end(), nod2);
		}
		fa[1] = 1;
		visit(1, 1, 0);
		rmq();
		while (m--)
		{
			scanf("%d%d", &x, &y);
			printf("%d\n", dist[x] + dist[y] - dist[lca(x, y)] * 2);
		}
	}
	return 0;
}
