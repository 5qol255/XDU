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
int gcd(int a, int b)
{
    int x;
    while (b != 0)
    {
        x = a % b;
        a = b;
        b = x;
    }
    return a;
}
int f(int a, int b)
{
    int x;
    x = gcd(a, b);
    return (a / x) * (b / x) * x;
}
int mian()
{
    int a, b;
    cin >> a >> b;
    if (b < a)
        swap(a, b);
    cout << gcd(a, b) << ' ' << f(a, b);
    return 0;
}