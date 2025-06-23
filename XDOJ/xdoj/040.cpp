#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a[114514];
    int sub;
    int i;
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (sub = a[1] - a[0], i = 1; i < n; ++i)
        if (a[i] - a[i - 1] != sub)
        {
            cout << "no" << endl;
            return 0;
        }
    cout << sub;
    return 0;
}