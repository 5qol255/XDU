#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b)
{
    if (!(a & 1) && (b & 1))
        return true;
    if ((a & 1) && !(b & 1))
        return false;
    return a > b;
}

int main()
{
    int n;
    int a[11111];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, cmp);
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    return 0;
}