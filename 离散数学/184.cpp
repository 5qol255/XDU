#include <bits/stdc++.h>
using namespace std;

bool cmp(const string a, const string b);
vector<string> split(string s, string a);
void f(vector<string> &a, int arr[], int index, int len, vector<string> &C);

int main()
{
    string s;
    vector<string> A, B, C;
    int n;
    int arr[10000];
    cin >> n >> s;
    if (n == 0)
    {
        cout << "{}";
        return 0;
    }
    s = split(s, "{")[1];
    s = split(s, "}")[0];
    A = split(s, ",");
    for (auto const &i : A)
        for (auto const &j : A)
            B.push_back("<" + i + "," + j + ">");
    f(B, arr, 0, B.size(), C);
    sort(C.begin(), C.end(), cmp);
    for (auto const &i : C)
        cout << i;
    return 0;
}

bool cmp(const string a, const string b)
{
    if (a.length() < b.length())
        return true;
    if (a.length() > b.length())
        return false;
    int i = 0;
    while (a[i] == b[i])
        ++i;
    return a[i] < b[i];
}

void f(vector<string> &a, int arr[], int index, int len, vector<string> &C)
{
    if (index == len)
    {
        string s;
        s += "{";
        for (int i = 0; i < len; i++)
        {
            if (arr[i] == 1)
            {
                s += a[i];
                if (i != len - 1)
                    s += ',';
            }
        }
        if (*s.rbegin() == ',')
        {
            *s.rbegin() = '}';
            s += "\n";
        }
        else
            s += "}\n";
        C.push_back(s);
    }
    else
    {
        arr[index] = 0;
        f(a, arr, index + 1, len, C);
        arr[index] = 1;
        f(a, arr, index + 1, len, C);
    }
}

vector<string> split(string s, string a)
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