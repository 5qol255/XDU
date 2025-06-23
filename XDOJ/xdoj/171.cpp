#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int id, time;
} stu;

bool cmp(stu a, stu b)
{
    if (a.time > b.time)
        return true;
    if (a.time < b.time)
        return false;
    return a.id < b.id;
}

int main()
{
    int n;
    int id, sh, eh, sm, em;
    vector<stu> a;
    cin >> n;
    for (auto i = 0; i < n; ++i)
    {
        scanf("%d %2d:%2d %2d:%2d", &id, &sh, &sm, &eh, &em);
        bool flag = false;
        for (auto &j : a)
            if (j.id == id)
            {
                j.time += em + 60 * eh - sm - 60 * sh;
                flag = true;
                break;
            }
        if (flag == false)
            a.push_back(stu{id, em + 60 * eh - sm - 60 * sh});
    }
    sort(a.begin(), a.end(), cmp);
    for (const auto &i : a)
        cout << i.id << ' ' << i.time << '\n';
    return 0;
}