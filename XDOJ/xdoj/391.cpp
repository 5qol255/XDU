#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i;
    long long a[54];
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n == 2)
    {
        cout << "1 1";
        return 0;
    }
    i = 3;
    a[1] = 1;
    a[2] = 1;
    while (i <= n)
    {
        a[i] = a[i - 1] + a[i - 2];
        ++i;
    }
    for (i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    return 0;
}