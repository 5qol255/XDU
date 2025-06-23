#include <bits/stdc++.h>

using namespace std;

int a[100010];

int main()
{
    int n, t;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        ++a[t];
    }
    for (int i = 0; i <= 100000; ++i)
        if (a[i] != 0)
            cout << i << ':' << a[i] << endl;
    return 0;
}