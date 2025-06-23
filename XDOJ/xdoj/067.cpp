#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    int a;
    bool flag = true;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        if (a == k)
        {
            cout << i << ' ';
            flag = false;
        }
    }
    if (flag)
        cout << -1;
    return 0;
}