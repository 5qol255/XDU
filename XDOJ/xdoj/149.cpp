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

int f(int n);
double g(int x);

int mian()
{
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 1; i <= n; ++i)
        sum += g(i);
    cout << fixed << setprecision(3) << sum;
    return 0;
}

double g(int x)
{
    return f(x + 1) * (double)x / (double)(2 * x - 1);
}

int f(int x)
{
    int i = 1;
    while (x != 0)
    {
        i *= -1;
        --x;
    }
    return i;
}