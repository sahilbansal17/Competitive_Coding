// https://practice.geeksforgeeks.org/problems/biconnected-graph/0

// C++ code to find the biconnected components in a graph
// as soon as a articulation point is found
// the no. of edges in the stack (stored edges discovered) 
// are popped till the top edge is same as that which discovered the AP

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int adj_matrix[MAX][MAX];

vector <bool> visited(MAX, 0);
vector <int> discovery_time(MAX, 0);
vector <int> low_time(MAX, 0);
vector <int> AP(MAX, 0);
vector <int> parent(MAX, -1);

// store the edges in each biconnected component
vector <vector <pair <int, int> > > biconnected_components;

// store the edges in the stack
stack <pair <int, int> > component_edges;

/* dfs function for finding biconnected components
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
				// push the edge source->v onto the stack
				component_edges.push({source, v});
				dfs_AP(V, v, time + 1);
				low_time[source] = min(low_time[source], low_time[v]);
				bool AP_found = false;
				if (parent[source] == -1 && num_children > 1) {
					// root having more than two distinct children
					AP[source] = 1;
					cerr << source << endl;
					// AP detected 
					AP_found = true;
				}
				if (parent[source] != -1 && low_time[v] >= discovery_time[source]) {
					// source has a child 'v' such that no vertex in the subtree
					// rooted at 'v' has a back edge to one of the ancestors of source
					// so, source is an articulation point
					AP[source] = 1;
					AP_found = true;
				}
				if (AP_found) {
					// pop and store all edges in the current component
					// from the stack till the edge source->v is found
					// those edges including source->v forms one BCC
					vector <pair <int, int> > current_component;
					pair <int, int> edge = {source, v};
					while (component_edges.top() != edge) {
						current_component.push_back(component_edges.top());
						component_edges.pop();
					}
					// edges {source -> v}
					current_component.push_back(component_edges.top());
					biconnected_components.push_back(current_component);
					component_edges.pop();
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
V = number of vertices 
considering the general case when graph can be disconnected */
void findBCC(int V) {
	// V vertices, source = 0, time = 1
	
	for (int i = 0; i < V; i ++) {
		if (!visited[i]) {
			dfs_AP(V, i, 1);
			// may happen that the stack component_edges is not empty
			vector <pair <int, int> > current_component;
			while (!component_edges.empty()) {
				current_component.push_back(component_edges.top());
				component_edges.pop();
			}
			biconnected_components.push_back(current_component);
		}
	}
}

int main () {
	
    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

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

	// find the biconnected components
	findBCC(num_vertices);

	// print the biconnected components
	/*
	int num_BCC = biconnected_components.size();
	cerr << "No. of BCC: " << num_BCC << endl;

	for (int i = 0; i < num_BCC; i ++) {
		cerr << "BCC " << i + 1 << endl;
		for (int j = 0; j < biconnected_components[i].size(); j ++) {
			cerr << biconnected_components[i][j].first << " " << biconnected_components[i][j].second << endl;
		} 
	}
	//*/

	// print the no. of BCC's with even and odd vertices
	// odd vertices => even edges in BCC
	// even vertices => odd edges in BCC

	int num_BCC = biconnected_components.size();

	int odd_vertiecs_BCC = 0, even_vertices_BCC = 0;
	for (int i = 0; i < num_BCC; i ++) {
		if (biconnected_components[i].size() % 2 == 0) {
			odd_vertiecs_BCC ++;
		}
		else {
			even_vertices_BCC ++;
		}
	}

	cout << odd_vertiecs_BCC << " " << even_vertices_BCC << endl;

	// reinitialize vectors to 0
	visited.assign(MAX, 0);
	discovery_time.assign(MAX, 0);
	low_time.assign(MAX, 0);
	AP.assign(MAX, 0);
	parent.assign(MAX, -1);

	// clear the vectors
	biconnected_components.clear();
	return 0;
}