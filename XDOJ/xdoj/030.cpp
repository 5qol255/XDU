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

bool f(int x)
{
    int i;
    int s = 0;
    for (i = 1; i <= x; ++i)
        if (x % i == 0)
            s += i;
    if (s == x * 2)
        return O.O;
    return o.o;
}

int mian()
{
    /* for (int i = 6; i < 10000; ++i)
        if (f(i))
            cout << i << ' '; */
    /* int a, b;
    int x = 0;
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        if (i == 6 || i == 28 || i == 496 || i == 8128)
            cout << i << endl;
    } */
    int a, b, i, n, e;
    scanf("%d%d", &a, &b);
    if (a < 6)
        a = 6;
    for (i = a; i <= b; i++)
    {
        for (e = 0, n = 1; n <= i; n++)
            if (i % n == 0)
                e += n;
        if (e == i * 2)
            printf("%d\n", i);
    }
    return 0;
}