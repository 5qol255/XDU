#include <bits/stdc++.h>
#define mian main
#define ll long long
#define elif else if

using namespace std;

int mian()
{
    int n;
    cin >> n;
    if (n % 2 == 0 && n % 3 != 0 && n % 5 != 0)
        cout << "Nice";
    else if (n % 3 == 0 && n % 2 != 0 && n % 5 != 0)
        cout
            << "Good";
    else if (n % 5 == 0 && n % 2 != 0 && n % 3 != 0)
        cout
            << "Best";
    else
        cout << "Bad";
    return 0;
}