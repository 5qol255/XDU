#include <bits/stdc++.h>

using namespace std;

double f(int n)
{
    if (n == 1)
        return sin(1);
    return sin(1.0 / n) + f(n - 1);
}

int main()
{
    double n;
    cin >> n;
    cout << fixed << setprecision(2) << f(n);
    return 0;
}