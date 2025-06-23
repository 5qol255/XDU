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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(max(max(a, b), c), d);
    return 0;
}