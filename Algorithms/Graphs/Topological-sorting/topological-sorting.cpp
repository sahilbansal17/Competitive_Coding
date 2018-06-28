
// Compile in C++11 or higher
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
using namespace std;

template<typename T>
class Graph
{
    map<T,list<T> > adjList;
public:
    Graph() {}
    void addEdge(T u,T v,bool bidir = true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
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

    void topologicalSort()
    {
        queue<T> q;
        map<T,bool> visited;
        map<T,int> indegree;
        for(auto i:adjList)
        {
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }
        // Initialize indegrees
        for(auto i: adjList)
        {
            T u = i.first;
            for(T v : adjList[u])
            {
                indegree[v]++;
            }
        }
        //Find nodes with 0 indegree
        for(auto i:adjList)
        {
            T node = i.first;
            if(indegree[node] ==0)
            {
                q.push(node);
            }
        }
        //Start with algorithm
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<"->";
            for(T neighbour:adjList[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);

                }
            }
        }
    }

};
int main()
{
    Graph<string> g;
    int E;
    string s,en;
    cout<<"\n How many edge you want to add";
    cin>>E;

    for(int i =0;i<E;i++){

        cout<<"\n Enter starting and Ending coordinates(First should be starting from 0)";
        cin>>s>>en;
        g.addEdge(s,en,false);
    }

    /*g.addEdge("English","ProgrammingLogic",false);
    g.addEdge("Maths","ProgrammingLogic",false);
    g.addEdge("ProgrammingLogic","HTML",false);
    g.addEdge("ProgrammingLogic","python",false);
    g.addEdge("ProgrammingLogic","Java",false);
    g.addEdge("ProgrammingLogic","JS",false);
    g.addEdge("Python","WebDev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("JS","WebDev",false);
    */g.print();
    g.topologicalSort();
    return 0;
}
// Time Complexity of above code is O(V+E)
                                      //Explanation of Time complexity
/* for complexity of topological sorting it just DFS with an extra stack so below i explain complexity of DFS so that you understand complexity of above algorithm
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
