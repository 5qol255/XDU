#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    string a, b;
    vector<vector<int>> dp(111, vector<int>(111, 0));
    int len1, len2, lsc;
    getline(cin, a);
    getline(cin, b);
    len1 = a.length();
    len2 = b.length();
    for (auto &i : a)
        if (i >= 'A' && i <= 'Z')
            i += 32;
    for (auto &i : b)
        if (i >= 'A' && i <= 'Z')
            i += 32;
    for (auto i = 0; i < len1; ++i)
        for (auto j = 0; j < len2; ++j)
        {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            if (dp[i + 1][j + 1] > lsc)
                lsc = dp[i + 1][j + 1];
        }
    cout << fixed << setprecision(3) << 2.0 * lsc / (len1 + len2);
    return 0;
}