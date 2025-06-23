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
    int n, k;
    int x = 0;
    int ans = 0;
    cin >> n >> k;
    while (n)
    {
        --n; // 喝汽水
        ++ans;
        ++x;        // 获得空瓶子
        if (x == k) // 兑换汽水
        {
            ++n;
            x = 0;
        }
    }
    cout << ans;
    return 0;
}