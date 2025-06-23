#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    double s;
    int t;
    cin >> s >> t;
    double x;
    x = (t / 5) * 2;
    if (s <= 3)
        x += 10;
    else if (s <= 10)
        x += 10 + (s - 3) * 2;
    else
        x += 10 + 14 + (s - 10) * 3;
    cout << (int)(x + 0.5);
    return 0;
}