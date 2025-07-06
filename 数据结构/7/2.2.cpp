#include <bits/stdc++.h>
using namespace std;
#define MaxVnum 50

typedef struct ArcNode
{
	int adjvex;				 // 邻接顶点的索引
	double weight;			 // 边的权重
	struct ArcNode *nextarc; // 指向下一个邻接点的指针
} ArcNode;

typedef struct
{
	int data;				 // 顶点的数据，这里使用顶点的索引作为数据
	vector<ArcNode> adjList; // 使用STL vector存储邻接表
} AdjList[MaxVnum];

typedef struct
{
	int vexnum, arcnum; // 图中顶点数和边数
	AdjList vertices;	// 邻接表数组
} Graph;

bool visited[MaxVnum]; // 访问标记数组

// 创建一个新的弧节点
ArcNode *createArcNode(int adjvex, double weight)
{
	ArcNode *newArcNode = new ArcNode;
	newArcNode->adjvex = adjvex;
	newArcNode->weight = weight;
	newArcNode->nextarc = nullptr;
	return newArcNode;
}

// 向图中添加边
void addEdge(Graph &G, int start, int end, double weight)
{
	ArcNode *newArcNode = createArcNode(end, weight);
	newArcNode->nextarc = G.vertices[start].adjList.empty() ? nullptr : &G.vertices[start].adjList[0];
	G.vertices[start].adjList.push_back(*newArcNode);
}

// 广度优先搜索函数
void BFS(Graph &G, int start)
{
	queue<int> q; // 使用STL queue
	visited[start] = true;
	q.push(start); // 将起始顶点加入队列

	while (!q.empty())
	{
		int v = q.front(); // 队列出队
		q.pop();
		cout << v << " "; // 访问顶点

		// 遍历所有邻接顶点
		for (auto &node : G.vertices[v].adjList)
		{
			if (!visited[node.adjvex])
			{
				visited[node.adjvex] = true;
				q.push(node.adjvex); // 邻接顶点入队
			}
		}
	}
}

int main()
{
	Graph G;
	int start, end;
	double weight;
	cin >> G.vexnum >> G.arcnum;
	// 初始化邻接表
	for (int i = 0; i < G.vexnum; i++)
	{
		G.vertices[i].data = i;
		G.vertices[i].adjList.clear();
	}

	// 初始化访问标记数组
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = false;

	// 读取边信息并添加到图中
	for (int i = 0; i < G.arcnum; i++)
	{
		cin >> start >> end >> weight;
		addEdge(G, start, end, weight);
	}

	// 从每个未访问的顶点开始广度优先搜索
	for (int i = 0; i < G.vexnum; i++)
		if (!visited[i])
			BFS(G, i);

	return 0;
}