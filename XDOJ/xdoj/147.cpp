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
    cin >> n;
    while (n != 0)
    {
        if (n & 1)
            sum += n;
        cin >> n;
    }
    cout << sum;
    return 0;
}