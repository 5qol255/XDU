#include<iostream>
#include<string>

using namespace std;

// short dp[10000][10000];
short dp[10000];

int lcs(const string& s1, const string& s2)
{
    // 不压缩版本
    // for (int i = 1;i <= s1.size();i++)
    //     for (int j = 1;j <= s2.size();j++)
    //         if (s1[i - 1] == s2[j - 1])
    //             dp[i][j] = dp[i - 1][j - 1] + 1;
    //         else
    //             dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    // return dp[s1.size()][s2.size()];

    // 状态压缩版本
    for (int i = 1;i <= s1.size();i++)
    {
        int old = 0;
        for (int j = 1;j <= s2.size();j++)
        {
            int tmp = dp[j];
            if (s1[i - 1] == s2[j - 1])
                dp[j] = old + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);
            old = tmp;
        }
    }
    return dp[s2.size()];
}

int main()
{
    string s1;
    cin >> s1;
    string s2(s1.rbegin(), s1.rend());
    cout << lcs(s1, s2);
    return 0;
}
