#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, s2;
    vector<char> b;
    cin >> s;
    s2 = s.substr(1, s.length());
    for (const auto &i : s2)
        if (i > s[0])
            cout << i;
        else
            b.push_back(i);
    cout << s[0];
    sort(b.begin(), b.end());
    for (const auto &i : b)
        cout << i;
    return 0;
}