#include <bits/stdc++.h>
using namespace std;

int a[33][33];
int m, n, k, t;
bool mark[55];
bool visit[33][33];

void find(int i, int j, int k);

int main()
{
	int ii = 0, jj = 0;
	int tmp, cnt = 0;
	cin >> n >> m >> t >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> tmp;
			a[i][j] = tmp;
			if (tmp == k )
			{
				ii = i;
				jj = j;
			}
		}
	find(ii, jj, k);
	for (int i = 1; i <= t; ++i)
		if (mark[i] == true)
			++cnt;
	cout << cnt << endl;
	return 0;
}

void find(int i, int j, int k)
{
	if (i < 0 || i >= n || j < 0 || j >= m || visit[i][j])
		return;
	visit[i][j] = true;
	if (a[i][j] == k)
	{
		find(i + 1, j, k);
		find(i - 1, j, k);
		find(i, j + 1, k);
		find(i, j - 1, k);
	}
	else
		mark[a[i][j]] = true;
}