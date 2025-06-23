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
    int i;
    double x;
    cin >> n;
    double max = -114514, min = 114514, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        x = x * 1.8 + 32;
        cout << fixed << setprecision(1) << x << ' ';
        if (i == 4)
            cout << endl;
        if (x > max)
            max = x;
        if (x < min)
            min = x;
        sum += x;
    }
    cout << endl;
    cout << fixed << setprecision(1) << min << ' ' << max << ' ' << sum / n;
    return 0;
}