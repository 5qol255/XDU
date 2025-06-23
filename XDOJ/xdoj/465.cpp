#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int win = 0, point = 0;
    string name;
} Team;

bool cmp(Team a, Team b)
{
    if (a.win > b.win)
        return true;
    else if (a.win == b.win)
        if (a.point > b.point)
            return true;
        else if (a.point == b.point)
            return a.name < b.name;
        else
            return false;
    else
        return false;
}

int main()
{
    int N;
    cin >> N;
    Team *teams = new Team[N];
    for (int i = 0; i < N; ++i)
        cin >> teams[i].name;
    for (int i = 0; i < N; ++i)
    {
        int tmp;
        for (int j = 0; j < N; ++j)
        {
            cin >> tmp;
            switch (tmp)
            {
            case 5:
                ++ ++teams[i].point;
                ++teams[i].win;
                break;
            case 4:
            case 3:
                ++ ++ ++teams[i].point;
                ++teams[i].win;
                break;
            case -5:
                ++teams[i].point;
            }
        }
    }
    sort(teams, teams + N, cmp);
    for (int i = 0; i < N; ++i)
        cout << teams[i].name << ' ' << teams[i].win << ' ' << teams[i].point << endl;
    return 0;
}