#include <bits/stdc++.h>

using namespace std;

int f(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return f(n - 1) + f(n - 2);
}

bool p(int x)
{
    if (x < 4)
        return x > 1;
    for (int i = 3; i * i <= x; ++ ++i)
        if (x % i == 0)
            return false;
    return true;
}

signed main()
{
    int n, x;
    cin >> n;
    x = f(n);
    if (p(x))
        cout << "yes";
    else
        cout << x;
    return 0;
}