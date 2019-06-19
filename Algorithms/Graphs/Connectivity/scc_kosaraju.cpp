// https://www.geeksforgeeks.org/strongly-connected-components/
// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/

// C++ code to find Strongly Connected Components using Kosaraju's algorithm

#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
/*	Function to call dfs
*	source	: source vertex
*	adj[]	: array of vectors to store adjacency list
*	visited	: bitset of size V to mark vertices visited/unvisited
*	res 	: stores the vertices in order of their finish time
*/
void dfs(int source, vector <int> adj[], bitset <MAX> &visited, vector <int> &res) {
	visited[source] = true;

	// for all unvisited adjacent vertices to 'source', call dfs on them
	for (int next_idx = 0; next_idx < adj[source].size(); next_idx ++) {
		int next_node = adj[source][next_idx];
		if (!visited[next_node]) {
			dfs(next_node, adj, visited, res);
		}
	}
	// the vertex 'source' has been fully explored
	// add it to the 'res' vector

	res.push_back(source);
}

/*	Function for the first dfs call in Kosaraju's algorithm
*	V 	: Number of vertices
*	adj : array of vectors to store the adjacency list
*	returns the vertices list in order of decreasing finish times
*/
vector <int> dfs1(int V, vector <int> adj[]) {
	
	// res stores the list of vertices in order of decreasing finish times
	vector <int> res;

	bitset <MAX> visited;
	// while there are unvisited vertices, call dfs on them
	for (int i = 0; i < V; i ++) {
		if (!visited[i]) {
			dfs(i, adj, visited, res);
		}
	}

	// reverse the 'res' vector
	reverse(res.begin(), res.end());

	return res; 
}

/*	Function for the second dfs call in the Kosaraju's algorithm
*	V 					: Number of vertices
*	adj 				: array of vectors to store the adjacency list of transpose of original graph
*	ordered_vertices	: list of vertices in order of decreasing finish times in original graph
*	return the vector <vector <int> > that stores the SCCs.
*/
vector <vector <int> > dfs2(int V, vector <int> adj[], vector <int> ordered_vertices) {
	// to store the SCCs
	vector <vector <int> > scc;

	bitset <MAX> visited;
	// store the vertices in the current SCC
	vector <int> vertices_in_current_scc;

	// pick one by one vertices from the ordered_vertices vector
	for (int i = 0; i < V; i ++) {
		int vertex = ordered_vertices[i];
		// if unvisited, then find vertices in its SCC
		if (!visited[vertex]) {
			dfs(vertex, adj, visited, vertices_in_current_scc);
			// add the 'vertices_in_current_scc' to the result 'scc'
			scc.push_back(vertices_in_current_scc);
		}
		// clear the 'vertices_in_current_scc'
		vertices_in_current_scc.clear();
	}

	return scc;
}


/*	Function to find the no. of strongly connected components
*	using Kosaraju's algorithm
*	V 		: Number of vertices
*	adj[] 	: array of vectors to represent the graph
*	returns the no. of SCCs
*/
int kosaraju(int V, vector <int> adj[]) {

	// step 1: call dfs on the graph to order the vertices in order
	// of decreasing finish times
	vector <int> ordered_vertices;	
	ordered_vertices = dfs1(V, adj);
	
	// step 2: take the transpose of the graph
	vector <int> adj_transpose[V];
 	for (int v = 0; v < V; v ++) {
 		for (int next_idx = 0; next_idx < adj[v].size(); next_idx ++) {
 			int next_node = adj[v][next_idx];
 			// edge from v -> next_node
 			// so, adj_transpose will have edge next_node -> v
 			adj_transpose[next_node].push_back(v);
 		}
 	}

	// step 3: consider one by one vertices from the vector 'ordered_vertices'
	// if the vertex is unvisited, call dfs on it to get the SCC formed by it

 	// create a vector of vectors to store the strongly connected components
 	vector <vector <int> > scc;
 	scc = dfs2(V, adj_transpose, ordered_vertices);
	
 	int num_scc = scc.size();
 	return num_scc;

}

int main () {

	int t;
	cin >> t;

	while (t --) {
		int num_nodes, num_edges;
		cin >> num_nodes >> num_edges;

		// adjacency list to store the graph
		vector <int> adj[num_nodes];
		int u, v;
		for (int edge_idx = 0; edge_idx < num_edges; edge_idx ++) {
			cin >> u >> v;
			u --;
			v --;
			adj[u].push_back(v);
		}

		cout << kosaraju(num_nodes, adj) << endl;
	}
	return 0;
}