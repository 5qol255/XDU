#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 物品结构体：保存物品编号、价值和重量。
struct Item {
    int id;
    int value;
    int weight;
};

vector<Item> items = {
    {1, 20, 10},
    {2, 30, 20},
    {3, 65, 30},
    {4, 40, 40},
    {5, 60, 50}
};

const int capacity = 100;
int bestValue = 0;
vector<int> currentChoice(5, 0);
vector<int> bestChoice(5, 0);

// 计算从第 index 个物品开始，剩余所有物品的价值总和。
// 这个值用于上界估计：如果当前价值加剩余价值仍不超过最优值，则可以剪枝。
int remainingValue(int index) {
    int sum = 0;
    for (int i = index; i < static_cast<int>(items.size()); ++i) {
        sum += items[i].value;
    }
    return sum;
}

// 使用回溯法搜索 0/1 背包的最优解。
// index: 当前考虑到第 index 个物品。
// currentWeight: 当前背包重量。
// currentValue: 当前背包价值。
// depthText: 用于打印搜索树的缩进。
void backtrack(int index, int currentWeight, int currentValue, const string& depthText) {
    cout << depthText << "level=" << index
         << ", weight=" << currentWeight
         << ", value=" << currentValue;

    // 重量超过容量时，当前分支不可行，直接剪枝。
    if (currentWeight > capacity) {
        cout << "  [prune: overweight]\n";
        return;
    }

    // 上界不可能超过当前最优值时，也可以剪枝。
    if (currentValue + remainingValue(index) <= bestValue) {
        cout << "  [prune: bound]\n";
        return;
    }

    cout << '\n';

    // 已经处理完所有物品，更新最优解。
    if (index == static_cast<int>(items.size())) {
        if (currentValue > bestValue) {
            bestValue = currentValue;
            bestChoice = currentChoice;
        }
        return;
    }

    // 分支 1：选择当前物品。
    currentChoice[index] = 1;
    cout << depthText << "├─ choose item " << items[index].id << '\n';
    backtrack(index + 1,
              currentWeight + items[index].weight,
              currentValue + items[index].value,
              depthText + "│  ");

    // 分支 2：不选择当前物品。
    currentChoice[index] = 0;
    cout << depthText << "└─ skip item " << items[index].id << '\n';
    backtrack(index + 1, currentWeight, currentValue, depthText + "   ");
}

int main() {
    cout << "Backtracking tree for 0/1 knapsack:\n";
    backtrack(0, 0, 0, "");

    cout << "\nBest value: " << bestValue << '\n';
    cout << "Best choice:";
    int totalWeight = 0;
    for (int i = 0; i < static_cast<int>(items.size()); ++i) {
        if (bestChoice[i]) {
            cout << " item" << items[i].id;
            totalWeight += items[i].weight;
        }
    }
    cout << "\nTotal weight: " << totalWeight << " Lbs\n";

    return 0;
}
