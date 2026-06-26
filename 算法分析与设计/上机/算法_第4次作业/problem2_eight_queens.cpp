#include <iostream>
#include <vector>

using namespace std;

const int n = 8;
vector<int> queenColumn(n, -1); // queenColumn[row] 表示第 row 行皇后所在列。
int solutionCount = 0;

// 判断在 (row, col) 放置皇后是否安全。
bool isSafe(int row, int col) {
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        int prevCol = queenColumn[prevRow];

        // 同列冲突。
        if (prevCol == col) {
            return false;
        }

        // 对角线冲突：行差等于列差。
        if (abs(prevRow - row) == abs(prevCol - col)) {
            return false;
        }
    }
    return true;
}

// 打印一个棋盘解。
void printBoard() {
    cout << "Solution " << solutionCount << ":\n";
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            cout << (queenColumn[row] == col ? 'Q' : '.') << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// 回溯搜索：逐行放置皇后。
void solve(int row) {
    if (row == n) {
        ++solutionCount;
        // 为了避免输出过长，只打印前 3 个解；总解数仍继续统计。
        if (solutionCount <= 3) {
            printBoard();
        }
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col)) {
            queenColumn[row] = col;
            solve(row + 1);
            queenColumn[row] = -1; // 回溯，撤销当前行的选择。
        }
    }
}

int main() {
    solve(0);
    cout << "Total solutions: " << solutionCount << '\n';
    return 0;
}
