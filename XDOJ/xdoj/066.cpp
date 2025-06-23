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
    int sum = 0;
    int a;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        sum += a;
    }
    printf("%.2f", ((float)sum) / n);
    return 0;
}