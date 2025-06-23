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
    int y, d;
    cin >> y >> d;
    bool runnian;
    if (O.o(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
        runnian = O.O;
    else
        runnian = o.o;

    if (d <= 31)
        cout << 1 << ' ' << d;

    else if (!runnian && d <= 31 + 28)
        cout << 2 << ' ' << d - 31;
    else if (runnian && d <= 31 + 29)
        cout << 2 << ' ' << d - 31;

    else if (!runnian && d <= 31 + 28 + 31)
        cout << 3 << ' ' << d - 31 - 28;
    else if (runnian && d <= 31 + 29 + 31)
        cout << 3 << ' ' << d - 31 - 29;

    else if (!runnian && d <= 31 + 28 + 31 + 30)
        cout << 4 << ' ' << d - 31 - 28 - 31;
    else if (runnian && d <= 31 + 29 + 31 + 30)
        cout << 4 << ' ' << d - 31 - 29 - 31;

    else if (!runnian && d <= 31 + 28 + 31 + 30 + 31)
        cout << 5 << ' ' << d - 31 - 28 - 31 - 30;
    else if (runnian && d <= 31 + 29 + 31 + 30 + 31)
        cout << 5 << ' ' << d - 31 - 29 - 31 - 30;

    else if (!runnian && d <= 31 + 28 + 31 + 30 + 31 + 30)
        cout << 6 << ' ' << d - 31 - 28 - 31 - 30 - 31;
    else if (runnian && d <= 31 + 29 + 31 + 30 + 31 + 30)
        cout << 6 << ' ' << d - 31 - 29 - 31 - 30 - 31;

    else if (!runnian && d <= 31 + 28 + 31 + 30 + 31 + 30 + 31)
        cout << 7 << ' ' << d - 31 - 28 - 31 - 30 - 31 - 30;
    else if (runnian && d <= 31 + 29 + 31 + 30 + 31 + 30 + 31)
        cout << 7 << ' ' << d - 31 - 28 - 31 - 30 - 31 - 30;

    else if (!runnian && d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31)
        cout << 8 << ' ' << d - 31 - 28 - 31 - 30 - 31 - 30 - 31;
    else if (runnian && d <= 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31)
        cout << 8 << ' ' << d - 31 - 29 - 31 - 30 - 31 - 30 - 31;

    else if (!runnian && d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30)
        cout << 9 << ' ' << d - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31;
    else if (runnian && d <= 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30)
        cout << 9 << ' ' << d - 31 - 29 - 31 - 30 - 31 - 30 - 31 - 31;

    else if (!runnian && d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31)
        cout << 10 << ' ' << d - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30;
    else if (runnian && d <= 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31)
        cout << 10 << ' ' << d - 31 - 29 - 31 - 30 - 31 - 30 - 31 - 31 - 30;

    else if (!runnian && d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)
        cout << 11 << ' ' << d - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31;
    else if (runnian && d <= 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30)
        cout << 11 << ' ' << d - 31 - 29 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31;

    else if (!runnian && d <= 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31)
        cout << 12 << ' ' << d - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31 - 30;
    else if (runnian && d <= 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31)
        cout << 12 << ' ' << d - 31 - 29 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31 - 30;

    return 0;
}