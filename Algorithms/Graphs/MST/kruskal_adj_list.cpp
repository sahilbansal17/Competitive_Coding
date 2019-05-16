// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

// C++ code to implement Kruskal's algorithm to find
// the Minimum Spanning Tree of a given connected graph

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

	int t;
	cin >> t;

	while (t --) {
		int n, e;
		cin >> n >> e;
		int x, y, w;

		vector <pair <int, pair <int, int> > > edges;

		for (int i = 0; i < e; i ++) {
			cin >> x >> y >> w;
			edges.push_back({w, {x, y}});
		}

		cout << spanningTree(n, e, edges) << endl;
	}

	return 0;
}

/*  Function to find the sum of weights of edges in minimum spanning tree
*   V: number of vertices
*   e: number of edges
*   edges: vector storing the edges in the graph
*/
int spanningTree(int V, int e, vector<pair <int, pair<int, int> > > edges) {
	
	// sum of edge weights on the mst
	long long minimum_cost = 0;

	// sort the edges based on their weight
	// for convenience, added weight as first in the edges pair
	sort(edges.begin(), edges.end());

	// initialize UnionFind object equal to the no. of vertices
	UnionFind subsets(V);

	// process all the edges
	for (int edge_idx = 0; edge_idx < e; edge_idx ++) {
		pair <int, pair <int, int> > current_edge = edges[edge_idx];

		int weight = current_edge.first;
		int first_node = current_edge.second.first;
		int second_node = current_edge.second.second;

		// use 0-based indexing for vertices
		first_node --;
		second_node --;

		// if current_edge doesn't form a cycle
		if (!subsets.isSameSet(first_node, second_node)) {
			// connect the nodes, i.e. add both the nodes in the same subset
			subsets.unionSet(first_node, second_node);

			// add weight of the edge to the MST cost
			minimum_cost += weight;
		}
	} 

	return minimum_cost;
}