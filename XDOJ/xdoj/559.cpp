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

int f(int x)
{
    int i = 10;
    while (x / i != 0)
        i *= 10;
    return i;
}

int mian()
{
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if ((a * a) % f(a) == a)
            cout << a << endl;
        else
            cout << "No\n";
    }
    return 0;
}