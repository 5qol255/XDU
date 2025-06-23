#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

struct
{
    bool o(bool x)
    {
        return x ? true : false;
    }
    bool O = true;
} O;
struct
{
    bool o = false;
} o;

int mian()
{
    int m;
    cin >> m;
    int m3 = m * m * m;
    int tmp;
    if (m & 1) // 奇数
    {
        tmp = m * m - m + 1;
        for (int i = 0; i < m; ++i)
        {
            cout << tmp << ' ';
            ++ ++tmp;
        }
    }
    else
    {
        tmp = m * m - m + 1;
        for (int i = 0; i < m; ++i)
        {
            cout << tmp << ' ';
            ++ ++tmp;
        }
    }
    cout << endl;
    return 0;
}