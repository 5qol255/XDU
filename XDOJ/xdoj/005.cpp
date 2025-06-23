#include <bits/stdc++.h>

using namespace std;

const int N = 33;
int mp[N][N];
bool destroy[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (auto i = 0; i < n; ++i)
        for (auto j = 0; j < m; ++j)
            cin >> mp[i][j];
    for (auto color = 1; color <= 9; ++color)
    {
        memset(destroy, false, sizeof(destroy));
        for (auto i = 0; i < n; ++i)
            for (auto j = 0; j < m - 2; ++j)
                if (mp[i][j] == color && mp[i][j + 1] == color && mp[i][j + 2] == color)
                {
                    destroy[i][j] = true;
                    destroy[i][j + 1] = true;
                    destroy[i][j + 2] = true;
                }
        for (auto i = 0; i < n - 2; ++i)
            for (auto j = 0; j < m; ++j)
                if (mp[i][j] == color && mp[i + 1][j] == color && mp[i + 2][j] == color)
                {
                    destroy[i][j] = true;
                    destroy[i + 1][j] = true;
                    destroy[i + 2][j] = true;
                }
        for (auto i = 0; i < n; ++i)
            for (auto j = 0; j < m; ++j)
                if (destroy[i][j])
                    mp[i][j] = 0;
    }
    for (auto i = 0; i < n; ++i)
    {
        for (auto j = 0; j < m; ++j)
            cout << mp[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}