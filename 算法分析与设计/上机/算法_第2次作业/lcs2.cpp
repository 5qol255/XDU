#include<iostream>
#include<string>

using namespace std;

short dp[10000][10000];

int lcs(const string& s1, const string& s2)
{
    for (int i = 1;i <= s1.size();i++)
        for (int j = 1;j <= s2.size();j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;

    int ans = -1;
    for (int i = 1;i <= s1.size();i++)
        for (int j = 1;j <= s2.size();j++)
            if (dp[i][j] > ans)
                ans = dp[i][j];
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
    return 0;
}
