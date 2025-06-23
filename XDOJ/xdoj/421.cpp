#include <bits/stdc++.h>
#define mian main
using ll = long long;

using namespace std;

const int N = 1e2 + 10;
bool left_[N], right_[N];

int mian()
{
    bool flag = false;
    int n;
    cin >> n;
    for (int l, r; cin >> l >> r;)
        left_[l] = right_[r] = true;
    for (auto i = 1; i <= n; ++i)
        if (left_[i] == false && right_[i] == true)
        {
            flag = true;
            cout << i << '\n';
        }
    if (flag == false)
        cout << "0\n";
    return 0;
}