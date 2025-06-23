#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    int mp[114][114];
    int min, max;
    int i, j, k;
    int mx, my; // 记录马鞍点坐标
    bool flag;

    cin >> m >> n;
    for (i = 0; i < m; ++i)
        for (j = 0; j < n; ++j)
            cin >> mp[i][j];

    for (i = 0; i < m; ++i)
    {
        for (min = 0xffffff, mx = i, j = 0; j < n; ++j)
            if (mp[i][j] < min)
            {
                min = mp[i][j];
                my = j;
            }
        for (max = mp[mx][my], flag = true, k = 0; k < m; ++k)
            if (mp[k][my] >= max && k != mx)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            cout << mx << ' ' << my << ' ' << mp[mx][my] << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}