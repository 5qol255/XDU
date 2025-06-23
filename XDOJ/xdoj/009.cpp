#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int n, k;
    cin >> n >> k;
    double a, b;
    a = 4 / 3.0 * 3.1415926 * (n / 10.0 / 2.0) * (n / 10.0 / 2.0) * (n / 10.0 / 2.0) * 7.86;
    b = 4 / 3.0 * 3.1415926 * (k / 10.0 / 2.0) * (k / 10.0 / 2.0) * (k / 10.0 / 2.0) * 19.3;
    printf("%.3lf %.3lf", a, b);
    return 0;
}