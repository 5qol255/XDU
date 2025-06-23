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
    int n;
    cin >> n;
    int x = 0;
    while (n != 1)
    {
        if (n & 1)
            n = n * 3 + 1;
        else
            n /= 2;
        ++x;
    }
    cout << x;
    return 0;
}