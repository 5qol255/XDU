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
    int x;
    int i;
    cin >> x;
    if (x == 0)
    {
        cout << 0;
        return 0;
    }
    for (i = 1; i * i < x; ++i)
        ;
    if (i * i == x)
        cout << i;
    else
        cout << "no";
    return 0;
}