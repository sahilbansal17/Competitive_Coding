// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int adj_matrix[MAX][MAX];

vector <bool> visited(MAX, 0);
vector <int> discovery_time(MAX, 0);
vector <int> low_time(MAX, 0);
vector <int> AP(MAX, 0);
vector <int> parent(MAX, -1);
vector <pair <int, int> > bridges;

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

/* dfs function for finding the bridges
V = number of vertices
source = source vertex
time = visiting time
calculates the vectors discovery_time, low_time & AP */
void dfs_Bridge(int V, int source, int time) {
	visited[source] = 1;
	discovery_time[source] = low_time[source] = time;
	int num_children = 0;
	for (int v = 0; v < V; v ++) {
		if (adj_matrix[source][v] == 1) {
			if (!visited[v]) {
				num_children ++;
				parent[v] = source;
				dfs_Bridge(V, v, time + 1);
				low_time[source] = min(low_time[source], low_time[v]);
				// no special condition for root
				if (low_time[v] > discovery_time[source]) {
					// edges source->v is a bridge if the earliest discovered vertex
					// that can be visited from any vertex in the subtree rooted at
					// vertex 'v' has discovery time strictly greater than that of source
					bridges.push_back({source, v});
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

/* function to find the bridges in the given praph
stored in adj_matrix[][MAX]
V = number of vertices */
void findBridges(int V) {
	// V verties, source = 0, time = 1
	dfs_Bridge(V, 0, 1);
}

int main () {
	int num_vertices, num_edges;
	cin >> num_vertices >> num_edges;

	int vertex_u, vertex_v;
	for (int i = 0; i < num_edges; i ++) {
		cin >> vertex_u >> vertex_v;
		adj_matrix[vertex_u][vertex_v] = 1;
		adj_matrix[vertex_v][vertex_u] = 1;
	}

	// find articulation points
	findAP(num_vertices);

	// print the articulation points
	int count = 0;
	vector <int> articulation_points;
	for (int i = 0; i < num_vertices; i ++) {
		if (AP[i] == 1) {
			count ++;
			articulation_points.push_back(i);
		}
	}
	cout << count << endl;
	for (auto v: articulation_points) {
		cout << v << " ";
	}
	cout << endl;

    // reinitialize vectors to 0
	visited.assign(MAX, 0);
	discovery_time.assign(MAX, 0);
	low_time.assign(MAX, 0);
	AP.assign(MAX, 0);
	// parent must be reinitialied to -1
	parent.assign(MAX, -1);

	// find bridges
	findBridges(num_vertices);

	// print the bridges
	cout << bridges.size() << endl;
	sort(bridges.begin(), bridges.end());
	for (int i = 0; i < bridges.size(); i ++) {
		cout << bridges[i].first << " " << bridges[i].second << endl;
	}

	return 0;
}