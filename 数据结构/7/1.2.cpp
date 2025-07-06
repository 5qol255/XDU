#include <bits/stdc++.h>
using namespace std;
#define MaxVnum 50

typedef struct ArcNode
{
	int adjvex;
	double weight;
	struct ArcNode *nextarc;
} ArcNode;
typedef struct
{
	int data;
	ArcNode *firstarc;
} AdjList[MaxVnum];
typedef struct
{
	int vexnum, arcnum;
	AdjList vertices;
} Graph;

int visited[MaxVnum];

ArcNode *createArcNode(int adjvex, double weight)
{
	ArcNode *newArcNode = (ArcNode *)malloc(sizeof(ArcNode));
	newArcNode->adjvex = adjvex;
	newArcNode->weight = weight;
	newArcNode->nextarc = NULL;
	return newArcNode;
}

void addEdge(Graph *G, int start, int end, double weight)
{
	ArcNode *newArcNode = createArcNode(end, weight);
	newArcNode->nextarc = G->vertices[start].firstarc;
	G->vertices[start].firstarc = newArcNode;
}

void DFS(Graph G, int v)
{
	visited[v] = 1;
	printf("%d ", v + 1);
	ArcNode *p = G.vertices[v].firstarc;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

int main()
{
	Graph G;
	scanf("%d %d", &G.vexnum, &G.arcnum);
	for (int i = 0; i < G.vexnum; i++)
	{
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i < G.vexnum; i++)
		visited[i] = 0;

	for (int i = 0; i < G.arcnum; i++)
	{
		int start, end;
		double weight;
		scanf("%d %d %lf", &start, &end, &weight);
		addEdge(&G, start, end, weight);
	}

	for (int i = 0; i < G.vexnum; i++)
		if (!visited[i])
			DFS(G, i);

	return 0;
}