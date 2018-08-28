// Union Find Algorithm to find a cycle in undirected Graph
//lavishsaluja
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Edge
{
	int source, destination;
};

struct Graph
{
	int v,e;
	struct Edge* edge;
};

struct Graph* CreateGraph(int v, int e)
{
	struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
	graph -> v = v;
	graph -> e = e;
	graph -> edge = (struct Edge*)(malloc(graph -> e * sizeof(struct Edge)));

	return graph;
}

int find(int parent[], int i)
{
	if(parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
	int xset = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
}

int Cycle(struct Graph* graph)
{
	int* parent = (int*)malloc(sizeof(int));
	memset(parent,-1,sizeof(graph -> v * sizeof(int)));

	for(int i = 0; i < graph->e; i ++)
	{
		int x = find(parent, graph->edge[i].source);
		int y = find(parent, graph->edge[i].destination);

		if(x == y)
			return 1;
		Union(parent, x, y);
	}
	return 0;
}

int main(void){
	int v = 3, e = 2;
	struct Graph* graph = CreateGraph(v,e);

	graph->edge[0].source = 0;
	graph->edge[0].destination = 1;

	graph->edge[1].source = 1;
	graph->edge[1].destination = 2;

	graph->edge[2].source = 0;
	graph->edge[2].destination = 2;

	if(Cycle(graph))
		printf("Cycle prsent!\n");
	else
		printf("No Cycle prsent!\n");
	return 0;
}