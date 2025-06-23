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
    cin >> n;
    int t, a;
    cin >> t;
    int max = -11451419, mm;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        t += a;
        if (fabs(a) > max)
        {
            max = fabs(a);
            mm = i + 1;
        }
    }
    cout << t << ' ' << mm;
    return 0;
}