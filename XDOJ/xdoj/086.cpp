#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 1e2 + 10;
ll d[N][N], pic[N][N];
ll ans;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    int x1, x2, y1, y2;
    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        // ++x1;
        // ++x2;
        // ++y1;
        // ++y2;
        ++d[x1 + 1][y1 + 1];
        --d[x2 + 1][y1 + 1];
        --d[x1 + 1][y2 + 1];
        ++d[x2 + 1][y2 + 1];
    }
    for (auto i = 1; i <= 101; ++i)
        for (auto j = 1; j <= 101; ++j)
        {
            pic[i][j] = d[i][j] + pic[i - 1][j] + pic[i][j - 1] - pic[i - 1][j - 1];
            if (pic[i][j] != 0)
                ++ans;
        }
    cout << ans << '\n';
    return 0;
}