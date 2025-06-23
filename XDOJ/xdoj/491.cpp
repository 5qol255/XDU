#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, T;
    cin >> T;
    for (int x = 0; x < T; ++x)
    {
        cin >> n;
        int **a = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; ++i)
            a[i] = (int *)calloc(n, sizeof(int));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        bool flag = true;
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int j = 0; j < i; ++j)
                if (a[i][j] != 0)
                {
                    flag = false;
                    break;
                }
            if (!flag)
                break;
        }
        free(a);
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}