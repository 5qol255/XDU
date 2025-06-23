#include <bits/stdc++.h>

using namespace std;

double f(int n)
{
    if (n == 0)
        return 100;
    return 0.5 * f(n - 1);
}

int main()
{
    int n;
    double s = 100.0;
    cin >> n;
    for (int i = 1; i < n; ++i)
        s += 2 * f(i);
    // cout << fixed << setprecision(3) << s << ' ' << f(n);
    printf("S=%.3lf h=%.3lf", s, f(n));
    return 0;
}