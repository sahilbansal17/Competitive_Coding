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
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.print();
    g.bfs(0);
    return 0;
}
// Time Complexity And Space Complexity of above code is O(V+E) and O(V)
// where V is vertex and E is edge
