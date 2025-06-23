#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x < 1)
        cout << x;
    else if (x < 10)
        cout << 2 * x - 1;
    else
        cout << 3 * x - 11;
    return 0;
}