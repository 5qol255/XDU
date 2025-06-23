#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int m, n, q, r;
    cin >> m >> n >> q >> r;
    if (q == m / n && r == m % n)
        cout << "yes";
    else
        cout << m / n << ' ' << m % n;
    return 0;
}