#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e2 + 10;
int a[N][N], b[N][N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    int i, j;
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            cin >> a[i][j];
    for (j = 0; j < m; ++j)
    {
        for (i = n - 1; i >= 0; --i)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}