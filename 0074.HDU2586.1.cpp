#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int son;
	int distance;
};

int n;
vector<node>v[40001];//����ӱ��
int deep[40001];//ÿ��������
int visitnum[80001];//��������2*n-1
int visitn[40001];//ÿ���������һ��������
int vnum;
int mins[80001][18];		//������Сֵ
int dist[40001];		//ÿ���㵽���ȵľ���distance
int fa[40001];

void visit(int m, int d, int dis)		//�����ر�š�����distance
{
	vector<node>::iterator p;
	deep[m] = d;
	dist[m] = dis;
	for (p = v[m].begin(); p != v[m].end(); p++)
	{
		if (fa[(*p).son]>-1)continue;
		fa[(*p).son] = m;
		visitnum[vnum++] = m;	//������ʵĵ�vnum�������ĸ���
		visit((*p).son, d + 1, dis + (*p).distance);
	}
	visitn[m] = vnum;		//ע����2���˳��
	visitnum[vnum++] = m;
}

void rmq()		//����������Сֵ
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

int lca(int x, int y)	//�������������
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
			v[i].clear();	//��ʼ��
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
