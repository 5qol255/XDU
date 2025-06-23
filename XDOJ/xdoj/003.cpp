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
    int a[1234];
    memset(a, 0, 1234);
    int n;
    int min = 0xfffffff;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            a[1111] = fabs(a[i] - a[j]);
            if (a[1111] == 0)
            {
                cout << 0;
                return 0;
            }
            else if (O.o(a[1111] < min) == O.O)
                min = a[1111];
        }
    cout << min;
    return 0;
}