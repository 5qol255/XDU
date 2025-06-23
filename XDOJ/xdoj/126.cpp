#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    double d, p, r;
    cin >> d >> p >> r;
    printf("%.2lf", log(p / (p - d * r)) / log(1 + r));
    return 0;
}