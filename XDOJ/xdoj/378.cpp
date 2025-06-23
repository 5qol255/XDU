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
    ll n;
    cin >> n;
    if (n & 1)
    {
        cout << -1;
        return 0;
    }
    for (int i = 32; i > 0; --i)
    {
        if ((n >> i - 1) & 1)
            cout << (1 << i - 1) << ' ';
    }
    return 0;
}