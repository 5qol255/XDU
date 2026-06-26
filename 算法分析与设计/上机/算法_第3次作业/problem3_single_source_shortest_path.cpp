#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// 边结构体：u -> v 的权重为 w。
struct Edge {
    int u;
    int v;
    int w;
};

int main() {
    const int INF = numeric_limits<int>::max() / 4;
    vector<char> vertexName = {'A', 'B', 'C', 'D', 'E'};

    // 根据邻接矩阵列出所有存在的有向边。
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 3},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 1, 1}, {3, 2, 5},
        {4, 3, 3}
    };

    const int n = static_cast<int>(vertexName.size());
    const int source = 0; // A 为源点。
    vector<int> dist(n, INF);
    vector<int> predecessor(n, -1);
    dist[source] = 0;

    // Bellman-Ford 算法：进行 |V|-1 轮松弛。
    for (int round = 1; round <= n - 1; ++round) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                predecessor[edge.v] = edge.u;
            }
        }
    }

    // 检查是否存在负权回路。
    for (const auto& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
            cout << "Negative cycle exists.\n";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "A to " << vertexName[i] << ": ";
        if (dist[i] == INF) {
            cout << "inf\n";
            continue;
        }

        cout << "distance = " << dist[i] << ", path = ";

        // 根据 predecessor 数组还原路径。
        vector<int> path;
        for (int v = i; v != -1; v = predecessor[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        for (int j = 0; j < static_cast<int>(path.size()); ++j) {
            if (j > 0) {
                cout << "->";
            }
            cout << vertexName[path[j]];
        }
        cout << '\n';
    }

    return 0;
}
