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
    map<T,list<T> > adjList; //Map for adjacency list
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
        //Iterate over the map
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
    // Starting of the implementation of BFS
    void bfs(T src)
    {
        queue<T> q;
        map<T,int>dist;
        map<T,T>parent;
        for(auto i:adjList)
        {
            dist[i.first] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            //For the neighbours of the current node,find out the nodes which are not visited

            for(int neighbour : adjList[node])
            {
                if(dist[neighbour] == INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] +1;
                    parent[neighbour] = node;
                }
            }

        }
        //Print the distance to all the nodes
        for(auto i:adjList)
        {
            T node = i.first;
            cout<<"Dist of"<<node<<"from"<<src<<"is"<<dist[node]<<endl;
        }
    }
};
int main()
{
    Graph<int> g;
    int E,s,en;
    cout<<"\n How many edge you want to add";
    cin>>E;

    for(int i =0;i<E;i++){

        cout<<"\n Enter starting and Ending coordinates(First should be starting from 0)";
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
    */
    g.print();
    g.bfs(0);
    return 0;
}
// Time Complexity And Space Complexity of above code is O(V+E) and O(V)
// where V is vertex and E is edge
                                             //Explanation of Time complexity

   /*Pseudocode of BFS:

  put starting node in the queue
  while queue is not empty
  get first node from the queue, name it v
  (process v)
  for each edge e going from v to other nodes
   put the other end of edge e at the end of the queue
   end pseudocode
As you can see, the worst case (which is what O means), is basically for all vertices if the graph, do a O(1) operation with them - getting it
from the queue, then for all outbound edges of v do another O(1) operation, adding their other end to the queue. Thus summing the first O(1)
operation for all vertices gives O(V) and summing the O(outbound edge count) over all the vertices gives O(E), which gives O(V)+O(E)=O(V+E). Without the processing of course, or assuming it is O(1) like adding the vertex to a list.

Note that for sparse graphs, where E = O(V), you have overall O(V). While for dense graphs where you have E=O(V^2), you get overall O(E).

And O(V+E)=O(max(V,E)) too. In fact all we discussed in terms of O, can be proven to be the case for omega(V+E) and theta(V+E), which means that
there is a first order polynomial in V+E which is upper bound to the execution steps count and another first order polynomial which is lower bound
to the execution steps.

I hope the above explanation makes sense */
