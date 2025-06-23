#include <bits/stdc++.h>
#define mian main

using namespace std;

int mian()
{
    // cout << acos(-1);
    int n;
    cin >> n;
    double pi = 0;
    int m = 1;
    double tmp = 1.0;
    double eps = pow(10, -6);
    while (tmp >= eps)
    {
        if (m & 1)
            pi += tmp;
        else
            pi -= tmp;
        ++m;
        tmp = 1.0 / (2 * m - 1);
    }
    // cout << fixed << setprecision(n) << pi * 4;
    printf("%.*lf", n, pi * 4);
    return 0;
}