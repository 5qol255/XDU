#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M, C;
    int x, y;
    int cnt = 0;
    int i, j;
    char maps[22][22];
    memset(maps, 0, sizeof(maps));

    cin >> N >> M >> C;
    for (i = 0; i < N; ++i)
        for (j = 0; j < M; ++j)
            cin >> maps[i][j];

    i = 0;
    j = C - 1;
    while (true)
    {
        if (!(i >= 0 && i < N && j >= 0 && j < M))
        {
            cout << "out" << ' ' << cnt << endl;
            return 0;
        }
        if (maps[i][j] != '*')
        {
            if (maps[i][j] == 'N')
            {
                maps[i][j] = '*';
                --i;
            }
            else if (maps[i][j] == 'S')
            {
                maps[i][j] = '*';
                ++i;
            }
            else if (maps[i][j] == 'W')
            {
                maps[i][j] = '*';
                --j;
            }
            else if (maps[i][j] == 'E')
            {
                maps[i][j] = '*';
                ++j;
            }
            ++cnt;
        }
        else
        {
            cout << "loop" << ' ' << cnt << endl;
            return 0;
        }
    }
    return 0;
}