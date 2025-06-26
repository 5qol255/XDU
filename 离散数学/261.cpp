#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int x, y, tmp;
    int R[100][100];

    cin >> x >> y;
    for (auto i = 0; i < x; i++)
        for (auto j = 0; j < y; j++)
            cin >> R[i][j];

    for (auto j = 0; j < y; j++)
    {
        for (auto i = 0; i < x; i++)
            cout << R[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}