//Name:Dhiraj Sharma
//Email-id:dhirajcoolssharma@gmail.com
// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to represent a weighted edge in graph
struct Edge
{
    int start, ending, weight;
};

// structure to represent a connected, undirected
// and weighted graph
struct Graph
{
    // V is Number of vertices, E is Number of edges
    int V, E;

    // graph is represented as an array of edges.
    // Since the graph is undirected, the edge
    // from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
//  It is similar like malloc which can be written as
//  graph->edge=(struct Edge*)malloc(graph->E*sizeof(struct Edge));
    graph->edge = new Edge[E];

    return graph;
}

// A structure to represent a subset for union-find
// union-find is also called as disjoint set or merge-find-set
struct subset
{
    int parent;
    int rank;
};

// A utility function to find set of an element i
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high
    // rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and
    // increment its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights.
// Used in qsort() function for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    // Tnis will store the resultant MST
    struct Edge result[V];
    // An index variable, used for result[]
    int e = 0;
     // An index variable, used for sorted edges
    int i = 0;

    // Step 1:  Sort all the edges in increasing order of their
    // weight using qsort function. If we are not allowed to
    // change the given graph, we can create a copy of
    // array of edges.
    // qsort (void* base, size_t num, size_t size, myComp(function created above));

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    // Allocate memory for creating V subsets
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.start);
        int y = find(subsets, next_edge.ending);

        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    // print the contents of result[] to display the
    // built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].start, result[i].ending,
                                                 result[i].weight);
    return;
}

// Driver program to test above functions
int main()
{
    // Let us create following weighted graph
    // Number of vertices in graph
    int V = 4;
    // Number of edges in graph
    int E = 5;
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].start  = 0;
    graph->edge[0].ending = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].start  = 0;
    graph->edge[1].ending = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].start  = 0;
    graph->edge[2].ending = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].start  = 1;
    graph->edge[3].ending = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].start  = 2;
    graph->edge[4].ending = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}
// It has three steps:
//1.To sort the graph's edges in increasing order of their weights
//2.Check whether the set of vertices forms a circle or not if no
//include it otherwise discar it.For this one need to use Union-Find
//Algorithm
//3.Repeat step 2 till edges<vertices-1,this is because a tress has
//edges=vertices-1
//Sorting of edges takes O(ELounion-find algorithm. The find and union
//operations can take atmost O(LogV) time. So overall complexity is
//O(ELogE + ELogV) time.
//The value of E can be atmost O(V2), so O(LogV) are O(LogE) same.
//Therefore, overall time complexity is O(ElogE) or O(ElogV)


