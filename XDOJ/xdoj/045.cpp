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
    int a[54];
    int max = -114514;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
        if (fabs(a[i + 1] - a[i]) > max)
            max = fabs(a[i] - a[i + 1]);
    cout << max;
    return 0;
}