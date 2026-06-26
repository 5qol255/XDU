#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 打印最优加括号方案。
// split[i][j] 表示矩阵 Ai 到 Aj 的最优划分点。
void printOptimalParentheses(const vector<vector<int>>& split, int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";
    printOptimalParentheses(split, i, split[i][j]);
    printOptimalParentheses(split, split[i][j] + 1, j);
    cout << ")";
}

// 使用动态规划求矩阵连乘的最少乘法次数。
// dimensions = <p0, p1, ..., pn> 表示有 n 个矩阵，
// 第 i 个矩阵 Ai 的维度为 p(i-1) x p(i)。
void matrixChainProduct(const vector<int>& dimensions, const string& caseName) {
    int n = static_cast<int>(dimensions.size()) - 1;

    // cost[i][j] 表示计算 Ai...Aj 所需的最少数乘次数。
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));

    // split[i][j] 记录最优划分点，用于还原最优加括号方式。
    vector<vector<int>> split(n + 1, vector<int>(n + 1, 0));

    // len 表示当前处理的矩阵链长度。
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;

            // 枚举最后一次乘法的划分点 k。
            for (int k = i; k < j; ++k) {
                int currentCost = cost[i][k]
                                + cost[k + 1][j]
                                + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (currentCost < cost[i][j]) {
                    cost[i][j] = currentCost;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << caseName << ": ";
    cout << "dimensions = <";
    for (int i = 0; i < static_cast<int>(dimensions.size()); ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << dimensions[i];
    }
    cout << ">\n";

    cout << "Minimum multiplication cost = " << cost[1][n] << "\n";
    cout << "Optimal parentheses = ";
    printOptimalParentheses(split, 1, n);
    cout << "\n\n";
}

int main() {
    vector<vector<int>> cases = {
        {3, 5, 2, 1, 10},
        {2, 7, 3, 6, 10},
        {10, 3, 15, 12, 7, 2},
        {7, 2, 4, 15, 20, 5}
    };

    vector<string> names = {"a", "b", "c", "d"};

    for (int i = 0; i < static_cast<int>(cases.size()); ++i) {
        matrixChainProduct(cases[i], names[i]);
    }

    return 0;
}
