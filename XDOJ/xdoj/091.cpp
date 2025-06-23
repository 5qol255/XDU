#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    double a, b, c, s, p;
    cin >> a >> b >> c;
    p = (a + b + c) / 2.0;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.2lf", s);
    return 0;
}