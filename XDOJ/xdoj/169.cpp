#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int y, m, d, size;
} file;

bool cmp(file a, file b)
{
    if (a.y > b.y)
        return true;
    if (a.y < b.y)
        return false;
    if (a.m > b.m)
        return true;
    if (a.m < b.m)
        return false;
    if (a.d > b.d)
        return true;
    if (a.d < b.d)
        return false;
    return a.size > b.size;
}

int main()
{
    file a[114];
    int n;
    char t;
    cin >> n;
    for (auto i = 0; i < n; ++i)
        cin >> a[i].y >> t >> a[i].m >> t >> a[i].d >> a[i].size;
    sort(a, a + n, cmp);
    for (auto i = 0; i < n; ++i)
        cout << a[i].y << '/' << a[i].m << '/' << a[i].d << ' ' << a[i].size << '\n';
    return 0;
}