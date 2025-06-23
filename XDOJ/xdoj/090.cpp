#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int n;
    cin >> n;
    cout << n / 100 + (n - n / 100 * 100) / 10 + n % 10;
    return 0;
}