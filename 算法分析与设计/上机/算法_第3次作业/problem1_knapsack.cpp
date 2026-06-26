#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// 物品结构体：保存编号、价值、重量以及单位重量价值。
struct Item {
    int id;
    double value;
    double weight;
    double ratio;
};

int main() {
    const int capacity = 100;
    vector<Item> items = {
        {1, 20, 10, 20.0 / 10},
        {2, 30, 20, 30.0 / 20},
        {3, 65, 30, 65.0 / 30},
        {4, 40, 40, 40.0 / 40},
        {5, 60, 50, 60.0 / 50}
    };

    // 一、分数背包：按单位重量价值从大到小贪心选择。
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });

    double remaining = capacity;
    double fractionalValue = 0;
    vector<double> takeWeight(items.size() + 1, 0);

    for (const auto& item : sortedItems) {
        if (remaining <= 0) {
            break;
        }

        // 如果剩余容量不足以装下整个物品，则只取一部分。
        double currentWeight = min(remaining, item.weight);
        takeWeight[item.id] = currentWeight;
        fractionalValue += currentWeight * item.ratio;
        remaining -= currentWeight;
    }

    cout << fixed << setprecision(2);
    cout << "Fractional knapsack maximum value: " << fractionalValue << '\n';
    for (int i = 1; i <= 5; ++i) {
        cout << "Item " << i << ": take " << takeWeight[i] << " Lbs\n";
    }

    // 二、0/1 背包：动态规划求最大价值。
    vector<int> weights = {10, 20, 30, 40, 50};
    vector<int> values = {20, 30, 65, 40, 60};
    vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= static_cast<int>(items.size()); ++i) {
        for (int w = 0; w <= capacity; ++w) {
            // 不选第 i 个物品。
            dp[i][w] = dp[i - 1][w];

            // 如果容量足够，可以尝试选择第 i 个物品。
            if (w >= weights[i - 1]) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    cout << "0/1 knapsack maximum value: " << dp[items.size()][capacity] << '\n';
    cout << "Chosen items:";

    // 从 dp 表中倒推被选择的物品。
    int w = capacity;
    for (int i = static_cast<int>(items.size()); i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << ' ' << i;
            w -= weights[i - 1];
        }
    }
    cout << '\n';

    return 0;
}
