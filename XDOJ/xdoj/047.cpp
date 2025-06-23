#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int h, m;
    cin >> h >> m;
    h *= 60;
    h += m;
    double T;
    T = 4 * (h / 60.0) * (h / 60.0) / (h / 60.0 + 2.0) - 20.0;
    printf("%.2lf", T);
    return 0;
}