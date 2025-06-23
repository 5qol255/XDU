#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll f(int n)
{
    if (n <= 2)
        return 1;
    if (n <= 4)
        return n - 1;
    return f(n - 2) + f(n - 3) + f(n - 4);
}

int main()
{
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}