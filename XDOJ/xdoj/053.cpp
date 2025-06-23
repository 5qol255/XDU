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
    if (n >= 90)
        cout << 'A';
    else if (n >= 80)
        cout << 'B';
    else if (n >= 70)
        cout << 'C';
    else if (n >= 60)
        cout << 'D';
    else
        cout << 'E';
    return 0;
}