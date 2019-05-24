// https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1
// https://www.geeksforgeeks.org/eulerian-path-and-circuit/

// C++ code to check whether a graph is Eulerian or not

#include <bits/stdc++.h>
using namespace std;

#define MAX 101

// adjacency list to store the graph
vector <int> adj[MAX];

/*	Function to check whether a graph is Eulerian
*	Input v: no. of vertices
*	Input e: no. of edges
* 	Output: returns 2 if the graph has Eulerian cycle
*			returns 1 if the graph has Eulerian path
*			returns 0 if the graph is not Eulerian (has none)
*/

void dfs(int source, bitset <MAX> &visited) {

	visited[source] = 1;
	for (auto v: adj[source]) {
		if (!visited[v]) {
			dfs(v, visited);
		}
	}
}

bool checkEulerianGraph(int v, int e) {

	// the degrees of a vertex is simply the size of its adjacency list

	// condition 1: all the vertices with non-zero degree must be connected
	bitset <MAX> visited;

	// count of the components formed by vertices having non-zero degree
	int count = 0; 
	for (int u = 0; u < v; u ++) {
		// if a vertex is not visited, call dfs
		if (!visited[u]) {
			dfs(u, visited);

			// if degree of u is non-zero, increase the count
			if (adj[u].size() != 0) {
				count ++;
			}
		}
	}

	// more than one connected components => return 0
	if (count > 1) {
		return 0;
	}

	// condition 2: if all vertices have even degree => eulerian cycle
	// condition 3: no. of vertices with odd degree = 2 => eulerian path
	bool eulerian_cycle = true;
	int count_odd_degree = 0;
	for (int u = 0; u < v; u ++) {
		if (adj[u].size() % 2 != 0) {
			count_odd_degree ++;
			eulerian_cycle = false;
		}
	}

	if (eulerian_cycle) {
		return 2;
	}
	else if (count_odd_degree == 2) {
		return 1;
	}
	else {
		return 0;
	}
}

int main () {

	int t;
	cin >> t;

	while (t --) {
		int v, e;
		cin >> v >> e;

		int u1, u2;
		for (int i = 0; i < e; i ++) {
			cin >> u1 >> u2;
			adj[u1].push_back(u2);
			adj[u2].push_back(u1);
		}

		bool res = checkEulerianGraph(v, e);
		cout << res << endl;

		for (int i = 0; i < v; i ++) {
			adj[i].clear();
		}
	}

}