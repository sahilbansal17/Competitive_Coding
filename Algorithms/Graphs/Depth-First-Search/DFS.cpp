//use c++11 or higher
//Don't try to run on code blocks
#include <iostream>
#include <map>
#include <list>
using namespace std;

template<typename T>
class Graph
{
    map<T, list<T> > adjList;

public :
    Graph()
    {
    }
    void addEdge(T u,T v,bool bidir = true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()      // Complexity O(V)
    {
        //Iteration
        for(auto i:adjList)
        {
            cout<<i.first<<"->";
            //i.second is LL
            for(T entry:i.second)
            {
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }
    void dfsHelper( T node, map<T,bool> &visited)
    {
        //Whenever to come to a node mark it visited
        visited[node] = true;
        cout<<node<<" ";
        //TRY TO find out neighbour node which is not visited yet
        for(T neighbour: adjList[node])      //O(E)
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour,visited);
            }
        }
    }
    void dfs( T src)             //O(V)
    {
        map<T,bool> visited;
        dfsHelper(src,visited);
    }


};
int main()
{
    Graph<int> g;
    int E,s,en;
    cout<<"\n How many edge you want to add";
    cin>>E;

    for(int i =0;i<E;i++){

        cout<<"\n Enter starting and Ending coordinates";
        cin>>s>>en;
        g.addEdge(s,en);
    }
    /*g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.print();
    */g.dfs(0);
    return 0;
}
// Time complexity of above algorithm is O(V+E)


                        //Explanation of Time complexity
  /* you have a connected graph with V nodes and E edges.

In DFS, you traverse each node exactly once. Therefore, the time complexity of DFS is at least O(V).

Now, any additional complexity comes from how you discover all the outgoing paths or edges for each node which, in turn, is dependent on the way your graph is implemented.
If an edge leads you to a node that has already been traversed, you skip it and check the next. Typical DFS implementations use a hash table to maintain the list of traversed
 nodes so that you could find out if a node has been encountered before in O(1) time (constant time).

If your graph is implemented as an adjacency matrix (a V x V array), then, for each node, you have to traverse an entire row of length V in the matrix to discover all its
outgoing edges. Please note that each row in an adjacency matrix corresponds to a node in the graph, and the said row stores information about edges stemming from the node.
So, the complexity of DFS is O(V * V) = O(V^2).
If your graph is implemented using adjacency lists, wherein each node maintains a list of all its adjacent edges, then, for each node, you could discover all its neighbors by traversing
its adjacency list just once in liner time. For a directed graph, the sum of the sizes of the adjacency lists of all the nodes is E (total number of edges). So, the complexity
of DFS is O(V) + O(E) = O(V + E).
For an undirected graph, each edge will appear twice. Once in the adjacency list of either end of the edge. So, the overall complexity will be O(V) + O (2E) ~ O(V + E).

I hope the above explanation makes sense */
