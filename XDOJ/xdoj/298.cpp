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
    int a, b;
    int z, x, c, v;
    cin >> a >> b;
    z = (a + b) * (a + b);
    x = (a - b) * (a - b);
    c = a * a + b * b;
    v = a * a - b * b;
    cout << max(max(max(z, x), c), v) << ' ' << min(min(min(z, x), c), v);
    return 0;
}