#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>/*for assigning maximum integer for all distances of vertices except for source vertex in function BellmanFord()*/
//Name- Jyoti Mishra(@jstjyoti)
//E mail-jyotimishra29091997@gmail.com
/*Bellmanford's algorithm is a dynamic programming algorithm which can give all possible shortest part from a given source vertex to all the vertex in the graph containing negative or positive weighted edges and not having any negative weight cycle(a cycle of graph resulting negative weight as whole).It is a dynamic programming algorithm as need to use previous solutions of subproblems becuase we don't know future paths at the begining */
/*It differs from floydWarshall's algorithm which gives all the shortest path from every pair of vertex but Bellmanford's Algorithm works for finding out shortest path from only given (single)source vertex. */ 
/*BellmanFord's algorithm is an dynamic programming method because like Dynamic Programming Problems, the algorithm calculate shortest paths in bottom-up manner. It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates shortest paths with at-most 2 edges, and so on. After the i-th(v-1) iteration of outer loop, the shortest paths with at most i edges are calculated.*/
/*graph is having V vertices,E edges and S is the source Vertex, these three are input from user */
int V,E,S;

/*AS I am using linked Representation of the graph so this is the structure denoting an edge which has two end(source and destination vertices and are directed having a weight(positive or negative)*/
struct Edge
{
    int s, d, w;//s:source ,d:destination and w:weight
};

/*I am taking a structure to represent a connected, directed and weighted graph*/
struct Graph
{
    int V, E;
    struct Edge* edge;
  /*a pointer to edge sturcute is used to denote all the 	edges present inside graph in a list fashion of pointers to edges*/
};
/*create() function is for reading number of vertices and edges creates the graph having a list of Edges
Time complexity is O(1) as all the operations are Constant time Operation and no extra variable is used so no space complexity.*/
struct Graph* create()
{
	//Allocating space to structure graph
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    //assigment of input values to graph
    graph->V = V;
    graph->E = E;

    //Creating the list for pointers to edges
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) ); 
    return graph;
}

/*showResult() Function displays the minimum distance of each vertex from Source vertex.
Time Complexity is O(n) as array of distances is used.
As no extra variable needed so no space complexity i.e., space complexity is constant*/
void showResult(int dist[])
{   
    printf("\nVertex\tDistance from %d Vertex\n",S);
    int i;
    for (i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
/*This is the Function for implementation of Bellmanford's algorithm for a graph having postive of negative weighted edges but not having negative weight cycle. 
At first we initialise all the distances of vertices as maximum integer value and distance of source vertex as .
The shortest path in a graph with V vertex can at most contain V-1 vertex ,so we iterate first i loop for V-1 times and within this loop we check and update distances for each vertex by taking each edges one by one as,
distance[destination vertex of edge]=[(distance[Source vertex of edge]+weight of edge) if(distance[Source of edge]+weight of edge) is less than current distance[destination vertex of the edge].

Time Complexity of this function is O((V-1)*E) as the max opertions are in a loop running for (v-1)*E times .
O(V)+O((V-1)*E)+O(V) is the key operations here for the Key Operations.Thus Time Complexity is O((V-1)*E)
*/

void BellmanFord(struct Graph * graph)
{ 
    int dist[V];
    int i,j;
    /*assignment of infinite(maximum int here )distance to all the edges*/
 
    for (i = 0; i < V; i++)
        dist[i]=INT_MAX;
    //distance of Source is assigned 0.
    dist[S]= 0;
 
    //for updating distance through each edge one by one
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].s;
 
            int v = graph->edge[j].d;
 
            int weight = graph->edge[j].w;
 
            if (dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    /*Upto this shortest distance would have been found .Now we check for negative Weight Cycles*/
	/*if we get further smaller distance then negative edge cycle is present*/
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].s;
 
        int v = graph->edge[i].d;
 
        int weight = graph->edge[i].w;
 
        if (dist[u] + weight < dist[v])
	   {
            printf("This graph contains negative edge cycle and can not be solved using BellmanFord Algorithm\n");
		 return;
	   }
	  
    }
 
    showResult(dist);
    //showing final result of all the distances from Source
}
/*from main() ,initialization of global variables(V,E,S) occurs through user input then Graph is created and all the detials of edges are also taken as input.Then this graph is passed to BellmanFord() fuction to find all the shortest path from given Source S.
Time Complexity of Overall Program is O(V*E).

*/
int main()
{ 
	printf("\nEnter the number of Vertices of Graph");
	scanf("%d ",&V);
	printf("\nEnter the number of Edges of Graph");
	scanf("%d ",&E);
    //calling the create graph function for creating the graph .
    struct Graph* graph = createGraph();
    printf("Enter your source vertex number\n");
    scanf("%d",&S);
    int i;
    //taking the details for each edges in the graph
    for(i=0;i<E;i++)
    {
        printf("\nEnter Source, destination, weight respectively of edge %d\n",i+1);
        scanf("%d",&graph->edge[i].s);
        scanf("%d",&graph->edge[i].d);
        scanf("%d",&graph->edge[i].w);
    }
    //Passing the created graph 
    BellmanFord(graph);
 
    return 0;
}
