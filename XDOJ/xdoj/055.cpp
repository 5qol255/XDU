#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

int A(int n);
int B(int n);

signed main()
{
    int n;
    long double sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        sum += 1.0 * A(i) / B(i);
    cout << fixed << setprecision(2) << sum;
    return 0;
}

int A(int n)
{
    if (n <= 2)
        return n + 1;
    return A(n - 1) + A(n - 2);
}

int B(int n)
{
    if (n <= 2)
        return n;
    return B(n - 1) + B(n - 2);
}