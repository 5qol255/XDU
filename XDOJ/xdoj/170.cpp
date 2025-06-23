#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    char id[24];
    int sum, en;
    void print()
    {
        cout << id << ' ' << sum << ' ' << en << '\n';
    }
} S;

S Stu[220];

bool cmp(S a, S b)
{
    if (a.sum > b.sum)
        return true;
    if (a.sum < b.sum)
        return false;
    if (a.en > b.en)
        return true;
    if (a.en < b.en)
        return false;
    if (strcmp(a.id, b.id) < 0)
        return true;
    return false;
}

int main()
{
    int n, m;
    cin >> m >> n;
    for (auto i = 0; i < m; ++i)
        cin >> Stu[i].id >> Stu[i].sum >> Stu[i].en;
    sort(Stu, Stu + m, cmp);
    for (auto i = 0; i < n; ++i)
        Stu[i].print();
    return 0;
}