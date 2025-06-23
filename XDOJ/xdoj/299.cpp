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
    double i;
    cin >> i;
    if (i <= 1e5)
        cout << (int)(i * 0.10);
    else if (i <= 2e5)
        cout << (int)(1e5 * 0.10 + (i - 1e5) * 0.075);
    else if (i <= 4e5)
        cout << (int)(1e5 * 0.10 + 1e5 * 0.075 + (i - 2e5) * 0.05);
    else if (i <= 6e5)
        cout << (int)(1e5 * 0.10 + 1e5 * 0.075 + 2e5 * 0.05 + (i - 4e5) * 0.03);
    else if (i <= 1e6)
        cout << (int)(1e5 * 0.10 + 1e5 * 0.075 + 2e5 * 0.05 + 2e5 * 0.03 + (i - 6e5) * 0.015);
    else
        cout << (int)(1e5 * 0.10 + 1e5 * 0.075 + 2e5 * 0.05 + 2e5 * 0.03 + 4e5 * 0.015 + (i - 1e6) * 0.01);
    return 0;
}