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
    double a;
    cin >> a;
    double sqrt = a;
    while (fabs(sqrt * sqrt - a) >= 1e-6)
        sqrt = 0.5 * (sqrt + a / sqrt);
    cout << fixed << setprecision(5) << sqrt;
    return 0;
}