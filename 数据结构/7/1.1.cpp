#include <bits/stdc++.h>
using namespace std;
#define MaxVnum 50

typedef int AdjMatrix[MaxVnum][MaxVnum];
typedef struct
{
	int vexnum, arcnum;
	AdjMatrix arcs;
} Graph;
int visited[MaxVnum];

void DFS(Graph G, int v)
{
	visited[v] = 1;
	printf("%d ", v + 1);
	for (int i = 0; i < G.vexnum; i++)
		if (G.arcs[v][i] == 1 && !visited[i])
			DFS(G, i);
}

int main()
{
	Graph G;
	scanf("%d %d", &G.vexnum, &G.arcnum);
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			scanf("%d", &G.arcs[i][j]);
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;

	for (int i = 0; i < G.vexnum; i++)
		if (!visited[i])
			DFS(G, i);

	return 0;
}