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
    int a[4];
    int i = 0;
    cin >> a[i++];
    cin >> a[i++];
    cin >> a[i++];
    cin >> a[i++];
    sort(a, a + 4);
    i = 0;
    cout << a[i++] << ' ';
    cout << a[i++] << ' ';
    cout << a[i++] << ' ';
    cout << a[i++];
    return 0;
}