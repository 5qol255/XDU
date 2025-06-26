#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, const string &a);

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    s1 = split(s1, "{")[1];
    s1 = split(s1, "}")[0];
    vector<int> a;
    for (auto const &i : split(s1, ","))
        a.push_back(i[0]);
    s2 = split(s2, "{")[1];
    s2 = split(s2, "}")[0];
    vector<int> b;
    for (auto const &i : split(s2, ","))
        b.push_back(i[0]);
    set<int> A(a.begin(), a.end()), B(b.begin(), b.end());
    set<int> C, CC, CCC, CCCC;

    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(CC, CC.begin()));
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(CCC, CCC.begin()));
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(CCCC, CCCC.begin()));

    string result;
    result += '{';
    if (!C.empty())
    {
        for (auto const &i : C)
        {
            result += (char)i;
            if (i >= 'a' && i <= 'z')
                result += ',';
        }
        *result.rbegin() = '}';
    }
    else
        result += '}';
    result += '\n';
    result += '{';
    if (!CC.empty())
    {
        for (auto const &i : CC)
        {
            result += (char)i;
            if (i >= 'a' && i <= 'z')
                result += ',';
        }
        *result.rbegin() = '}';
    }
    else
        result += '}';
    result += '\n';
    result += '{';
    if (!CCC.empty())
    {
        for (auto const &i : CCC)
        {
            result += (char)i;
            if (i >= 'a' && i <= 'z')
                result += ',';
        }
        *result.rbegin() = '}';
    }
    else
        result += '}';
    result += '\n';
    result += '{';
    if (!CCCC.empty())
    {
        for (auto const &i : CCCC)
        {
            result += (char)i;
            if (i >= 'a' && i <= 'z')
                result += ',';
        }
        *result.rbegin() = '}';
    }
    else
        result += '}';

    cout << result;
}

vector<string> split(string s, const string &a)
{
    vector<string> list;
    int x;
    while ((x = s.find(a)) != string::npos)
    {
        list.push_back(s.substr(0, x));
        s = s.substr(x + a.length());
    }
    list.push_back(s.substr(0, x));
    return list;
}