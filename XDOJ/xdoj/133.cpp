#include <bits/stdc++.h>

using namespace std;

struct term
{
    int coef, epx;
};

bool cmp(term a, term b)
{
    return a.epx < b.epx;
}

int main()
{
    int n, m, t;
    int tmp1, tmp2;
    vector<term> expr1, expr2, expr;
    cin >> n >> m >> t;
    for (auto i = 0; i < n; ++i)
    {
        cin >> tmp1 >> tmp2;
        expr1.push_back(term{tmp1, tmp2});
    }
    for (auto i = 0; i < m; ++i)
    {
        cin >> tmp1 >> tmp2;
        tmp1 = t == 0 ? tmp1 : -tmp1;
        expr2.push_back(term{tmp1, tmp2});
    }
    for (const auto &i : expr1)
    {
        bool flag = false;
        for (auto &j : expr2)
            if (i.epx == j.epx)
            {
                j.coef += i.coef;
                flag = true;
                break;
            }
        if (flag == false)
            expr.push_back(i);
    }

    expr.insert(expr.end(), expr2.begin(), expr2.end());
    sort(expr.begin(), expr.end(), cmp);

    bool flag = true;
    for (const auto &i : expr)
    {
        if (i.coef != 0 && flag == false)
        {
            if (i.epx == 0 && i.coef > 0)
                cout << '+' << i.coef;
            else if (i.epx == 0 && i.coef < 0)
                cout << i.coef;
            else if (i.epx == 1 && i.coef == 1)
                cout << "+x";
            else if (i.epx == 1 && i.coef > 1)
                cout << '+' << i.coef << 'x';
            else if (i.epx == 1 && i.coef == -1)
                cout << "-x";
            else if (i.epx == 1 && i.coef < -1)
                cout << i.coef << 'x';
            else if (i.coef == 1)
                cout << "+x^" << i.epx;
            else if (i.coef > 1)
                cout << '+' << i.coef << "x^" << i.epx;
            else if (i.coef == -1)
                cout << "-x^" << i.epx;
            else if (i.coef < -1)
                cout << i.coef << "x^" << i.epx;
        }
        else if (i.coef != 0 && flag == true)
        {
            flag = false;
            if (i.epx == 0)
                cout << i.coef;
            else if (i.epx == 1 && i.coef == 1)
                cout << 'x';
            else if (i.epx == 1 && i.coef > 1)
                cout << i.coef << 'x';
            else if (i.epx == 1 && i.coef == -1)
                cout << "-x";
            else if (i.epx == 1 && i.coef < -1)
                cout << i.coef << 'x';
            else if (i.coef == 1)
                cout << "x^" << i.epx;
            else if (i.coef > 1)
                cout << i.coef << "x^" << i.epx;
            else if (i.coef == -1)
                cout << "-x^" << i.epx;
            else if (i.coef < -1)
                cout << i.coef << "x^" << i.epx;
        }
    }
    return 0;
}