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
    int y, m;
    cin >> y >> m;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << 30;
        break;
    case 2:
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
            cout << 29;
        else
            cout << 28;
    }
    return 0;
}