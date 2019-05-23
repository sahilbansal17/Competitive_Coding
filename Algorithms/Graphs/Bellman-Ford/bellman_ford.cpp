// https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0
// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

/*  C++ code to implement Bellman Ford's algorithm
*   to find shortest path from a source vertex
*   to all other vertices in the graph
*   This is used to check whether the graph contains a negative cycle
*/

#include <bits/stdc++.h>
using namespace std;

/*  Function to relax an edge
*   u : source vertex
*   v : destination vertex
*   e : edge weight
*   dist: vector storing distance of all from bellman source vertex (not u)
*/

bool relax(int u, int v, int w, vector <int> &dist) {

    // both vertices u and v are not visited from bellman source
    if (dist[u] == INT_MAX && dist[v] == INT_MAX) {
        return false;
    }

    if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        return true;
    }
    return false;
}

/*  Bellman ford function to check negative cycle
*   v = no. of verties
*   e = no. of edges
*   edges = vector of {x, {y, w}} such that x->y is an edge of weight w
*/
bool bellman_ford(int source, int v, int e, vector <pair <int, pair <int, int> > > edges, vector <int> &dist) {

    // till i-th iteration, paths with atmost i edges are considered
    for (int i = 0; i <= v - 1; i ++) {

        // consider all the edges and relax the edges if possible
        for (int edge_idx = 0; edge_idx < e; edge_idx ++) {

            pair <int, pair <int, int> > edge;
            edge = edges[edge_idx];
            int first_node = edge.first;
            int second_node = edge.second.first;
            int weight = edge.second.second;

            bool possible = relax(first_node, second_node, weight, dist);
        }
    }

    // after the end, no more edge should be relaxed if no negative cycle
    for (int edge_idx = 0; edge_idx < e; edge_idx ++) {
        pair <int, pair <int, int> > edge;
        edge = edges[edge_idx];
        int first_node = edge.first;
        int second_node = edge.second.first;
        int weight = edge.second.second;
        if (relax(first_node, second_node, weight, dist)) {
            // negative weight cycle found
            return true;
        }
    }
    return false;
}

int main () {

    int t;
    cin >> t;

    int v, e;
    while (t --) {
        cin >> v >> e;

        int x, y, w;
        vector <pair <int, pair <int, int> > > edges;
        vector <bool> visited(v, 0);
        for (int i = 0; i < e; i ++) {
            cin >> x >> y >> w;
            edges.push_back({x, {y, w}});
        }

        bool negative_cycle;

        // while there are unvisited vertices (disconnected graph)
        for (int i = 0; i < v; i ++) {
            if (!visited[i]) {

                // initialize the distance of all the vertices from the source vertex
                vector <int> dist(v, INT_MAX);
                dist[i] = 0;

                // check whether there is a negative cycle
                // in the connected component of this vertex
                // by running bellman ford with 'i' as source
                negative_cycle = bellman_ford(i, v, e, edges, dist);
                if (negative_cycle) {
                    // report negative cycle
                    cout << "1" << endl;
                    break; 
                }
                // mark all vertices whose distance is known as visited
                for (int i = 0; i < v; i ++) {
                    if (dist[i] != INT_MAX) {
                        visited[i] = 1;
                    }
                }
            }
        }
        
        // no negative cycle
        if (!negative_cycle) {
            cout << "0" << endl;
        }
    }

    return 0;
}