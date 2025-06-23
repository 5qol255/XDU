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

void pyramid(int n)
{
    /* if (n == 1)
    {
        cout << 'A';
        return;
    } */
    int a, b, i, j;
    a = n - 1 + 'A';
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n - i - 1; ++j)
            cout << ' ';
        for (b = 'A'; b <= 'A' + i; ++b)
            printf("%c", b);
        // cout << ' ';
        for (b = 'A' + i - 1; b >= 'A'; --b)
            printf("%c", b);
        cout << endl;
    }
}

int mian()
{
    char c;
    cin >> c;
    pyramid(c - 'A' + 1);
    return 0;
}