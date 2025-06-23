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

int f(int x);

int mian()
{
    int n;
    int t;
    int num = -114514;
    int sum_o_n = -114514;
    int tmp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        tmp = f(t);
        if (sum_o_n < tmp || (sum_o_n == tmp && t > num))
        {
            sum_o_n = tmp;
            num = t;
        }
    }
    cout << num;
    return 0;
}

int f(int x)
{
    int b = 0;
    while (x != 0)
    {
        b += (x % 10);
        x /= 10;
    }
    return b;
}
