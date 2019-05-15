// https://practice.geeksforgeeks.org/problems/biconnected-graph/0

// C++ code to check whether a graph is biconnected
// i.e. it must be connected
// and it should not have any articulation point

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int adj_matrix[MAX][MAX];

vector <bool> visited(MAX, 0);
vector <int> discovery_time(MAX, 0);
vector <int> low_time(MAX, 0);
vector <int> AP(MAX, 0);
vector <int> parent(MAX, -1);

/* dfs function for finding articulation points
V = number of vertices
source = source vertex
time = visiting time
calculates the vectors discovery_time, low_time & AP */
void dfs_AP(int V, int source, int time) {
	visited[source] = 1;
	discovery_time[source] = low_time[source] = time;
	int num_children = 0;
	for (int v = 0; v < V; v ++) {
		if (adj_matrix[source][v] == 1) {
			if (!visited[v]) {
				num_children ++;
				parent[v] = source;
				dfs_AP(V, v, time + 1);
				low_time[source] = min(low_time[source], low_time[v]);
				if (parent[source] == -1 && num_children > 1) {
					// root having more than two distinct children
					AP[source] = 1;
				}
				if (parent[source] != -1 && low_time[v] >= discovery_time[source]) {
					// source has a child 'v' such that no vertex in the subtree
					// rooted at 'v' has a back edge to one of the ancestors of source
					// so, 'source' is an articulation point
					AP[source] = 1;
				}
			}
			else if (parent[source] != v) {
				// back edge
				low_time[source] = min(low_time[source], discovery_time[v]);
			}
		}
	}
}

/* function to find the articulation points in the given graph
stored in adj_matrix[][MAX]
V = number of vertices */
void findAP(int V) {
	// V vertices, source = 0, time = 1
	dfs_AP(V, 0, 1);
}

int main () {
	int t;
	cin >> t;

	while (t --) {
		int num_vertices, num_edges;
		cin >> num_vertices >> num_edges;

		// clear the adj_matrix
		memset(adj_matrix, 0, sizeof(adj_matrix));

		int vertex_u, vertex_v;
		for (int i = 0; i < num_edges; i ++) {
			cin >> vertex_u >> vertex_v;
			adj_matrix[vertex_u][vertex_v] = 1;
			adj_matrix[vertex_v][vertex_u] = 1;
		}

		// find articulation points
		findAP(num_vertices);

		// print the articulation points and visited vertices
		int count_AP = 0, count_visited = 0;
		for (int i = 0; i < num_vertices; i ++) {
			if (AP[i] == 1) {
				count_AP ++;
			}
			if (visited[i] == 1) {
				count_visited ++;
			}
		}

		if (count_AP == 0 && count_visited == num_vertices) {
			// biconnected graph
			cout << "1" << endl;
		}
		else {
			// not biconnected graph
			cout << "0" << endl;
		}

		// reinitialize vectors to 0
		visited.assign(MAX, 0);
		discovery_time.assign(MAX, 0);
		low_time.assign(MAX, 0);
		AP.assign(MAX, 0);
		parent.assign(MAX, -1);
	}
	return 0;
}