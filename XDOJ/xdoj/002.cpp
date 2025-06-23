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
    int a, b = 114514;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (a != b)
            ++cnt;
        b = a;
    }
    cout << cnt;
    return 0;
}