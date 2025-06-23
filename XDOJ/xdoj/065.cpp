#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

int f(int x)
{
    if (x < 10)
        return x;
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    return f(sum);
}

signed main()
{
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}