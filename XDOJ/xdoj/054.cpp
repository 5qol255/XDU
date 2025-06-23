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
    int a, b, c;
    int n;
    cin >> n;
    for (a = 1; a <= 9; ++a)
        for (b = 0; b <= 9; ++b)
            for (c = 1; c <= 9; ++c)
                if (a * 100 + b * 10 + c + c * 100 + b * 10 + a == n)
                    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}