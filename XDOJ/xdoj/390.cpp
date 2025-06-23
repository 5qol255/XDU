#include <bits/stdc++.h>

using namespace std;

int fact(int n);

int main()
{
    int n;
    cin >> n;
    fact(n);
    return 0;
}

int fact(int n)
{
    if (n == 1)
    {
        cout << 1 << ' ';
        return 1;
    }
    int x = n * fact(n - 1);
    cout << x << ' ';
    return x;
}