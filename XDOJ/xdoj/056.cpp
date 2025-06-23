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
    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    if (a * a + b * b == c * c)
        cout << a * b;
    else if (a * a + c * c == b * b)
        cout << a * c;
    else if (c * c + b * b == a * a)
        cout << c * b;
    else
        cout << "no";
    return 0;
}