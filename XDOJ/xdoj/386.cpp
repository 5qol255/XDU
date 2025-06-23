#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    double t;
    cin >> t;
    printf("%.2lf\n%.2lf\n%c", t * 0.6, 50.0 + t * 0.4, t * 0.6 < 50.0 + t * 0.4 ? 'A' : 'B');
    return 0;
}