#include <bits/stdc++.h>

using namespace std;

struct node
{
    int n, sum;
};

bool cmp(struct node a, struct node b)
{
    if (a.sum > b.sum)
        return true;
    if (a.sum < b.sum)
        return false;
    return a.n < b.n;
}

int main()
{
    int n;
    char s[114];
    struct node a[1111];
    int i, j;

    cin >> n;
    for (i = 0; i < n; ++i)
    {
        cin >> s;
        for (a[i].sum = 0, j = 0; j < strlen(s); ++j)
            a[i].sum += s[j] - '0';
        sscanf(s, "%d", &a[i].n);
    }
    sort(a, a + n, cmp);
    for (i = 0; i < n; ++i)
        cout << a[i].n << ' ' << a[i].sum << endl;
    return 0;
}