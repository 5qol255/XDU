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
    int a, b;
    cin >> a >> b;
    cout << max(a, b) % 10 << ' ' << min(a, b) * min(a, b) << endl;
    return 0;
}