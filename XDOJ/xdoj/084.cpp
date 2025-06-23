#pragma GCC cdtimize(2)
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string cwd, op, cd;
    cin >> cwd;
    while (true)
    {
        cin >> op;
        if (op == "pwd")
            break;
        cin >> cd;
        if (cd[0] == '/')
            cwd = cd;
        else if (cd == "..")
        {
            if (cwd.length() >= 1)
                cwd.erase(cwd.begin() + cwd.rfind('/'), cwd.end());
            if (cwd.length() == 0)
                cwd = "/";
        }
        else
        {
            if (cwd.length() != 1)
                cwd += '/';
            cwd += cd;
        }
    }
    cout << cwd << '\n';
    return 0;
}
