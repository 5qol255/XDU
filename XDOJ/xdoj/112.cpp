#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
    if (x >= 0)
        return sqrt(x);
    return (x + 1) * (x + 1) + 2 * x + 1.0 / x;
}

int main()
{
    double x;
    cin >> x;
    cout << fixed << setprecision(2) << f(x);
    return 0;
}