#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int n;
    cin >> n;
    int a[] = {100, 50, 20, 10, 5, 1, 0};
    int i = 0, j;
    while (a[i] != 0)
    {

        j = n / a[i];
        n -= j * a[i];
        cout << j << ' ';
        ++i;
    }
    return 0;
}