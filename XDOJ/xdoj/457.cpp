#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a[114];
    cin >> n;
    for (int i = 0; i < (n << 1); ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cout << a[i + n] << ' ';
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    return 0;
}