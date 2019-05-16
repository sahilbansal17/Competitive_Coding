// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

// C++ code to implement Prim's algorithm to find
// the Minimum Spanning Tree of a given connected graph

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, int e, vector <pair <int, int> > adj[]);

int main () {

	int t;
	cin >> t;

	while (t --) {
		int n, e;
		cin >> n >> e;
		int x, y, w;

		vector <pair <int, int> > adj_list[n + 1];

		for (int i = 0; i < e; i ++) {
			cin >> x >> y >> w;
			adj_list[x].push_back({y, w});
			adj_list[y].push_back({x, w});
		}

		cout << spanningTree(n, e, adj_list) << endl;
	}

	return 0;
}

/*  Function to find the sum of weights of edges in minimum spanning tree
*   V: number of vertices
*   e: number of edges
*   adj[]: array of vectors representing the graph
*/
int spanningTree(int V, int e, vector<pair<int, int>> adj[]) {
	
	// sum of edge weights on the mst
	long long minimum_cost = 0;

	// inMST[i] denotes whether vertex i is present in the MST
	vector <int> inMST(V + 1, 0);

	// pq (min heap implementation) contains vertex not in MST with their smallest previous edge distance
	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;

	// source vertex: 1, distance 0
	// first of the pair, i.e. distance is the key in pq (smallest key pair will be on the top)
	pq.push({0, 1});

	// process till no more vertex to be added in the MST
	while (!pq.empty()) {
		// extract the node with smallest key value
		pair <int, int> best_node;
		best_node = pq.top();
		pq.pop();

		int current_vertex = best_node.second;
		int edge_weight = best_node.first;

		// if current vertex already marked to be in the MST, cycle can be formed
		if (inMST[current_vertex] == 1) {
			continue;
		}

		// mark the current vertex to be in the MST
		inMST[current_vertex] = 1;

		// cerr << current_vertex << " " << edge_weight << endl;
		// add its edge weight to the cost of the MST
		minimum_cost += edge_weight;

		for (int next_idx = 0; next_idx < adj[current_vertex].size(); next_idx ++) {
			int next_vertex = adj[current_vertex][next_idx].first;
			int next_distance = adj[current_vertex][next_idx].second;
			if (!inMST[next_vertex]) {
				pq.push({next_distance, next_vertex});
			}
		}
	}

	return minimum_cost;
}