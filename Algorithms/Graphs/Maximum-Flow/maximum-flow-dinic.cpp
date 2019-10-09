#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

struct Edge {
    int v; // vertex v in an edge from u to v
    int flow; // flow of data in an edge
    int C; // Capacity
    int rev; // To store index of reverse edge
};

class Graph {
    int V; // number of vertices
    vector<int> level; // level of a graph;
    vector<vector<Edge>> adj;

    public:
    Graph(int V){
        adj = vector<vector<Edge>>(V);
        this->V = V;
        level = vector<int>(V);
    }

    void addEdge(int u, int v, int C);
    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, vector<int> &start);
    int maxFlow(int s, int t);
};

void Graph::addEdge(int u, int v, int C) {
    Edge a{v, 0, C, int(adj[v].size())}; //Forward Edge: 0 flow and C capacity
    Edge b{u, 0, 0, int(adj[u].size())}; //Back edge: 0 flow and 0 capacity

    adj[u].push_back(a);
    adj[v].push_back(b); //reverse edge
}

bool Graph::BFS(int s, int t) {
    for(int i = 0;i < V;i++)
        level[i] = -1;
    
    level[s] = 0; //Level of source vertex


    list<int> q;
    q.push_back(s);
    //Enque source vertex and mark it as visited level[] array also works as visited array
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(auto edge : adj[u]) {
            if(level[edge.v] < 0 && edge.flow < edge.C){
                // Level of current vertex = level of parent vertex + 1
                level[edge.v] = level[u] + 1;
                q.push_back(edge.v);
            }
        }
    }
    // if we reach the sink we return true else false
    return level[t] >= 0;
}

int Graph::sendFlow(int s, int flow, int t, vector<int> &start) {
    /*
        A DFS based function to send flow after it's figured out that there is a
        possible flow.
        flow: Current flow
        start[]: To keep track of next edge
        s: source vertex
        t: sink
    */
    if(s == t) // Sink reached
        return flow;
    
    for(; start[s] < adj[s].size(); start[s]++) {
        Edge &e = adj[s][start[s]];
        if(level[e.v] == level[s]+1 && e.flow < e.C) {
            int curr_flow = min(flow, e.C - e.flow);
            int temp_flow = sendFlow(e.v, curr_flow, t, start);

            if(temp_flow > 0) {
                e.flow += temp_flow;

                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int Graph::maxFlow(int s, int t) {
    /*
     Returns maximum flow in the graph
    */
    if(s == t) // Corner Case
        return -1;
    
    int total = 0; // Initialize resources

    while(BFS(s, t)) { //Augment the flow when there is path from source to sink
        vector<int> start(V, 0);// Edges visited from 0 to V
        while(int flow = sendFlow(s, INT_MAX, t, start)) //While flow is not zero from s to t
            total += flow; // Add path to overall flow
    }

    return total;
}

int main(int argc, char const *argv[])
{
    //Example Code
    //Graph g(6);
    // g.addEdge(0, 1, 16 ); 
    // g.addEdge(0, 2, 13 ); 
    // g.addEdge(1, 2, 10 ); 
    // g.addEdge(1, 3, 12 ); 
    // g.addEdge(2, 1, 4 ); 
    // g.addEdge(2, 4, 14); 
    // g.addEdge(3, 2, 9 ); 
    // g.addEdge(3, 5, 20 ); 
    // g.addEdge(4, 3, 7 ); 
    // g.addEdge(4, 5, 4); 
    //cout << "Maximum flow: " << g.maxFlow(0, 5);

    int V, u, v, c, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    Graph g(V);
    cout << "Enter edge details: u v C\n";
    for(int i = 0;i < E;i++) {
        cin >> u >> v >> c;
        g.addEdge(u, v, c);
    }
    cout << "Enter source and sink: ";
    cin >> u >> v;
    cout << "Maximum flow: " << g.maxFlow(u, v);
    return 0;
}
