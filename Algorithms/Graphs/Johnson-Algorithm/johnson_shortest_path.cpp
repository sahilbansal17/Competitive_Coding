// https://www.geeksforgeeks.org/johnsons-algorithm/
// https://www.spoj.com/problems/JHNSN/

// C++ code for Johnson's algorithm to find all pairs shortest paths

#include <bits/stdc++.h>
using namespace std;

#define MAX 101
vector <pair <int, int> > adj[MAX], adj_new[MAX];
vector <pair <int, pair <int, int> > > edges;

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
bool bellman_ford(int source, int v, int e, vector <int> &dist) {

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


/*  Function to find the shortest path from source
*	using Dijkstra's algorithm
*	source: the source vertex
*   V: number of vertices
*   e: number of edges
*   adj[]: array of vectors representing the graph
*	h: vector of distance readjustments found by bellman ford
*	sp: short form for shortest path used in comments
*/
void dijkstra(int source, int V, int e, vector <int> &dist, vector <int> h) {

	// shortest_path_found[i] denotes whether vertex i's shortest path is finalized
	vector <int> shortest_path_found(V + 1, 0);

	// pq (min heap implementation) contains vertex whose sp is not found with their smallest distance from source
	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;

	// source vertex: parameter to the function, distance 0
	// first of the pair, i.e. distance is the key in pq (smallest key pair will be on the top)
	pq.push({0, source});
	dist[source] = 0;

	// process till no more vertex to be added in the MST
	while (!pq.empty()) {
		// extract the node with smallest distance from source (sp not finalized)
		pair <int, int> best_node;
		best_node = pq.top();
		pq.pop();

		int current_vertex = best_node.second;
		int sp_distance = best_node.first;

		if (shortest_path_found[current_vertex] == 1) {
			continue;
		}
		// mark the current vertex to have its sp finalized
		shortest_path_found[current_vertex] = 1;

		// process all neighbouring vertices
		for (int next_idx = 0; next_idx < adj_new[current_vertex].size(); next_idx ++) {
			int next_vertex = adj_new[current_vertex][next_idx].first;
			int edge_weight = adj_new[current_vertex][next_idx].second;

			// relaxation condition
			if (!shortest_path_found[next_vertex] && dist[next_vertex] > edge_weight + dist[current_vertex]) {
				dist[next_vertex] = dist[current_vertex] + edge_weight;
				
				pq.push({dist[next_vertex], next_vertex});
			}
		}
	}

	// make readjustments for correct weights in original graph
	for (int i = 1; i <= V; i ++) {
		if (dist[i] != INT_MAX) {
			dist[i] = dist[i] - (h[source] - h[i]);
		}
	}
}

int johnson(int t_no, int n, int m) {

	// step 1: create a new vertex (0) and add edge from it to all other vertices
	for (int i = 1; i <= n; i ++) {
		edges.push_back({0, {i, 0}});
	}

	// step 2: run bellman ford with (0) as the source
	vector <int> h(n + 1, INT_MAX);
	h[0] = 0;
	bool negative_cycle = bellman_ford(0, n + 1, m + n, h);
	if (negative_cycle) {
		return 0;
	}
	else {
		cout << "graph " << t_no + 1 << " ";
		cout << "yes" << endl << endl;

		// print the h_vector
		for (int i = 1; i <= n; i ++) {
			cout << h[i] << " ";
		}
		cout << "0"; // h(n + 1), i.e. new vertex
		cout << endl << endl;
	}

	// step 3: reweight all the edges of the original graph
	// wt'(u, v) = wt(u, v) + h[u] - h[v]

	for (int i = 0; i < m; i ++) {
		pair <int, pair <int, int> > edge;
		edge = edges[i];
		int first_node = edge.first;
		int second_node = edge.second.first;
		int weight = edge.second.second;
		weight += h[first_node] - h[second_node];
		adj_new[first_node].push_back({second_node, weight});
	}

	// step 4: run dijkstra's algo for all the vertices 1 to n
	// in the graph formed by adj_new

	vector <vector <int> > all_pair_dist;
	vector <int> cur_dist;
	for (int i = 1; i <= n; i ++) {
		cur_dist.assign(n + 1, INT_MAX);
		dijkstra(i, n, m, cur_dist, h);
		all_pair_dist.push_back(cur_dist);
	}

	// print the all-pair shortest paths
	for (int i = 0; i < n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (all_pair_dist[i][j] != INT_MAX) {
				cout << all_pair_dist[i][j] << " ";
			}
			else {
				cout << "# ";
			}
		}
		cout << endl;
	}
	return 1;
}

int main () {

	int t;
	cin >> t;

	int n, m;
	for (int t_no = 0; t_no < t; t_no ++) {
		cin >> n >> m;

		int u, v, w;
		for (int i = 0; i < m; i ++) {
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			edges.push_back({u, {v, w}});
		}

		int res = johnson(t_no, n, m);

		if (res == 0) {
			cout << "graph " << t_no + 1 << " ";
			cout << "no" << endl;
		}

		cout << endl;
		for (int i = 1; i <= n; i ++) {
			adj[i].clear();
			adj_new[i].clear();
		}
		edges.clear();
	}
}