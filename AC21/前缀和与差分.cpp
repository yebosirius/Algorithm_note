/*#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int nums[N], sum[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%d", &nums[i]);
	for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + nums[i];
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << sum[r] - sum[l - 1];
		cout << endl;
	}
}*/
//矩阵前缀.两个前缀都只需要维护一个序列,多维护一个序列带来的复杂度提升是巨大的
/*#include <iostream>

using namespace std;

const int N = 1010;
int nums[N][N];
int n, m, k;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &nums[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			nums[i][j] += nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1];

	while (k--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n",nums[x2][y2] + nums[x1 - 1][y1 - 1] - nums[x1 - 1][y2] - nums[x2][y1 - 1]);
	}
}*/

//差分:某个区间内,整体加减
/*#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int n, m;
int nums[N], res[N];

void add(int l, int r, int c)
{
	res[l] += c;
	res[r + 1] -= c;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", &nums[i]);
	for (int i = 1; i <= n; i++)add(i, i, nums[i]);
	while (m--)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		add(l, r, c);
	}
	for (int i = 1; i <= n; i++)nums[i] = nums[i - 1] + res[i];
	for (int i = 1; i <= n; i++)printf("%d ", nums[i]);
}*/
//差分矩阵
/*
#include <iostream>

using namespace std;

const int N = 1010;
int nums[N][N], res[N][N];

void build(int x1, int y1, int x2, int y2, int c)
{
	res[x1][y1] += c;
	res[x1][y2 + 1] -= c;
	res[x2 + 1][y1] -= c;
	res[x2 + 1][y2 + 1] += c;
}

int n, m, q;

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &nums[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			build(i, j, i, j, nums[i][j]);

	while (q--)
	{
		int x1, y1, x2, y2, c;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
		build(x1, y1, x2, y2, c);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			nums[i][j] = nums[i - 1][j] + nums[i][j - 1] - nums[i - 1][j - 1] + res[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)printf("%d ", nums[i][j]);
		cout << endl;
	}


}*/
int res(int i,int j)
{
	return 1;
}
void build(int x1, int y1, int x2, int y2, int c)
{
	res[x1][y1] += c;
	res[x1][y2 + 1] -= c;
	res[x2 + 1][y1] -= c;
	res[x2 + 1][y2 + 1] += c;
}
