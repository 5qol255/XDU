#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    const int INF = numeric_limits<int>::max() / 4;
    vector<char> vertexName = {'A', 'B', 'C', 'D', 'E'};

    // 邻接矩阵，INF 表示两点之间没有直接边。
    vector<vector<int>> dist = {
        {0, -1, 3, INF, INF},
        {INF, 0, 3, 2, 2},
        {INF, INF, 0, INF, INF},
        {INF, 1, 5, 0, INF},
        {INF, INF, INF, 3, 0}
    };

    const int n = static_cast<int>(vertexName.size());

    // Floyd 算法：逐个枚举中间点 k。
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "All-pairs shortest distance matrix:\n    ";
    for (char name : vertexName) {
        cout << name << "   ";
    }
    cout << '\n';

    for (int i = 0; i < n; ++i) {
        cout << vertexName[i] << "   ";
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << "inf ";
            } else {
                cout << dist[i][j] << "   ";
            }
        }
        cout << '\n';
    }

    return 0;
}
