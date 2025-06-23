#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int m;
    int a[22][22];
    int sum[514];
    int i, j, p = 0;
    memset(sum, 0, 514);

    cin >> m;
    for (i = 0; i < m; ++i)
        for (j = 0; j < m; ++j)
            cin >> a[i][j];

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < m; ++j)
            sum[p] += a[i][j];
        ++p;
    }
    for (j = 0; j < m; ++j)
    {
        for (i = 0; i < m; ++i)
            sum[p] += a[i][j];
        ++p;
    }
    for (i = 0; i < m; ++i)
        sum[p] += a[i][i];
    ++p;
    for (j = m - 1; j >= 0; --j)
        sum[p] += a[m - 1 - j][j];
    ++p;
    sort(sum, sum + p, cmp);
    for (i = 0; i < p; ++i)
        cout << sum[i] << ' ';
    return 0;
}