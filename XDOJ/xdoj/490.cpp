#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, n;
    int t = 0;
    int g;
    cin >> N >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> g;
        if (g < 0)
            goto c1;
        else if (g > N)
            cout << "Too big\n";
        else if (g < N)
            cout << "Too small\n";
        else if (g == N && i == 0)
            goto c2;
        else if (g == N && i < 3)
            goto c3;
        else
            goto c4;
    }
    goto c1;
c1:
    cout << "Game Over\n";
    return 0;
c2:
    cout << "Bingo!\n";
    return 0;
c3:
    cout << "Lucky You!\n";
    return 0;
c4:
    cout << "Good Guess!\n";
    return 0;
}
