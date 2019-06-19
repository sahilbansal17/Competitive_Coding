// https://www.geeksforgeeks.org/boruvkas-algorithm-greedy-algo-9/
// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

/*  C++ code to implement Boruvka's algorithm to find
*   the Minimum Spanning Tree of a given connected graph
*   Boruvka's algorithm:
*   -------------------
*   • Input is a connected, weighted and directed graph
*   • Initialize all vertices as individual components (or sets)
*   • Initialize MST as empty
*   • While there are more than once components, do following:
*       • Find the closest edge that connects this component to another
*       • Add this closest edge to MST if not already added.
*   • Return MST
*/

#include <bits/stdc++.h>
using namespace std;

/*  Union-Find Disjoint Sets Library written in OOP manner
*   using both path compression and union by rank heuristics
*   source: CP-3 by Steven Halim
*/
class UnionFind {
private:
    vector <int> p, rank, setSize; 
    int numSets;
public:
    UnionFind(int N){
        setSize.assign(N, 1); 
        numSets = N; 
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i; 
    }
    int findSet(int i){ 
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }
    bool isSameSet(int i, int j){ 
        return findSet(i) == findSet(j); 
    }
    void unionSet(int i, int j){ 
        numSets--; 
        int x = findSet(i), y = findSet(j);
        // rank is used to keep the tree short
        if (rank[x] > rank[y]){
            p[y] = x; 
            setSize[x] += setSize[y];
        }
        else{ 
            p[x] = y; 
            setSize[y] += setSize[x];
            if(rank[x] == rank[y]) 
                rank[y]++; 
        } 
    }
    int numDisjointSets(){ 
        return numSets; 
    }
    int sizeOfSet(int i){ 
        return setSize[findSet(i)]; 
    }
};

int spanningTree(int V, int e, vector <pair <int, pair <int, int> > > edges);

int main () {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    int t;
    cin >> t;

    while (t --) {
        int n, e;
        cin >> n >> e;
        int x, y, w;

        vector <pair <int, pair <int, int> > > edges;

        for (int i = 0; i < e; i ++) {
            cin >> x >> y >> w;
            // 0-based indexing
            x --;
            y --;
            edges.push_back({w, {x, y}});
            // edges.push_back({w, {y, x}});
        }

        cout << spanningTree(n, e, edges) << endl;
    }

    return 0;
}

/*  Function to find the sum of weights of edges in minimum spanning tree
*   V: number of vertices
*   e: number of edges
*   edges: vector containing all the edges {w, {x, y}}: x->y weight = w
*/
int spanningTree(int V, int e, vector<pair <int, pair <int, int> > > edges) {
    
    // sum of edge weights on the mst
    long long minimum_cost = 0;

    // initialize UnionFind object equal to the no. of vertices
    UnionFind subsets(V);

    // minimum cost edge to connect one component to another
    // stores the index of the edge
    vector <int> min_cost_edge;

    while (subsets.numDisjointSets() != 1) {
        // while there are more than one components

        // assign -1 (no edge) to min_cost_edge vector
        min_cost_edge.assign(V, -1);

        // iterate over all edges
        for (int i = 0; i < e; i ++) {
            int first_node = edges[i].second.first;
            int second_node = edges[i].second.second;
            long long weight = edges[i].first;

            if (!subsets.isSameSet(first_node, second_node)) {
                // are not in the same connected component

                // find their set_numbers
                int set_first = subsets.findSet(first_node);
                int set_second = subsets.findSet(second_node);

                // update min_cost_edge for two components
                if (min_cost_edge[set_first] == -1) {
                    min_cost_edge[set_first] = i;
                }
                else if (weight < edges[min_cost_edge[set_first]].first) {
                    min_cost_edge[set_first] = i;
                }

                if (min_cost_edge[set_second] == -1) {
                    min_cost_edge[set_second] = i;
                }
                else if (weight < edges[min_cost_edge[set_second]].first) {
                    min_cost_edge[set_second] = i;
                }
            }
        }

        // join components through the inter-component edges
        for (int i = 0; i < V; i ++) {
            if (min_cost_edge[i] == -1) {
                continue;
            }

            // get the min_cost_edge for this component
            int edge_id = min_cost_edge[i];
            int first_node = edges[edge_id].second.first;
            int second_node = edges[edge_id].second.second;
            long long weight = edges[edge_id].first;

            // if edge not already included in the MST
            if (!subsets.isSameSet(first_node, second_node)) {
                // join the two components
                subsets.unionSet(first_node, second_node);

                // add its weight to the MST cost
                minimum_cost += weight;
            }
        }
    }

    return minimum_cost;
}