#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int max_len, len;
    cin >> s;
    max_len = s.length();
    while (s.find_last_of(".") == -1)
    {
        cin >> s;
        len = s.length();
        if (s.find_last_of(".") != -1)
            --len;
        if (len > max_len)
            max_len = len;
    }
    cout << max_len;
    return 0;
}