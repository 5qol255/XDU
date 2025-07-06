#include <bits/stdc++.h>
using namespace std;
#define MaxVnum 50

typedef int AdjMatrix[MaxVnum][MaxVnum];

typedef struct
{
	int vexnum, arcnum;
	AdjMatrix arcs;
} Graph;

bool visited[MaxVnum];

// 向图中添加边
void addEdge(Graph &G, int start, int end, int weight)
{
	G.arcs[start][end] = weight; // 邻接矩阵中设置权重
}

// 广度优先搜索函数
void BFS(Graph G, int start)
{
	queue<int> q; // 使用STL queue
	visited[start] = true;
	q.push(start); // 将起始顶点加入队列

	while (!q.empty())
	{
		int v = q.front(); // 队列出队
		q.pop();
		cout << v << " "; // 访问顶点

		for (int i = 0; i < G.vexnum; i++)
		{
			if (G.arcs[v][i] && !visited[i])
			{ // 存在边且未访问
				visited[i] = true;
				q.push(i); // 邻接顶点入队
			}
		}
	}
}

int main()
{
	Graph G;
	cin >> G.vexnum >> G.arcnum;
	memset(G.arcs, 0, sizeof(G.arcs));
	memset(visited, 0, sizeof(visited));
	int start, end, weight;
	for (int i = 0; i < G.arcnum; i++)
	{
		cin >> start >> end >> weight;
		addEdge(G, start, end, weight);
	}

	for (int i = 0; i < G.vexnum; i++)
		if (!visited[i])
			BFS(G, i);

	return 0;
}