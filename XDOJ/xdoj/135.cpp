#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main()
{
    char s[114];
    vector<ll> num;
    ll n;
    gets(s);
    int len = strlen(s);
    for (auto i = 0, j = i; i < len; ++i)
        if (s[i] >= '0' && s[i] <= '9')
        {
            for (j = i; s[j] >= '0' && s[j] <= '9'; ++j)
                ;
            sscanf(s + i, "%lld", &n);
            num.push_back(n);
            i = j - 1;
        }
    sort(num.begin(), num.end(), greater<ll>());
    for (const auto &i : num)
        cout
            << i << ' ';
    return 0;
}