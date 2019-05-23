// https://open.kattis.com/contests/wjchfk/problems/equivalences
// http://algorithms-live.blogspot.com/2017/06/episode-23-strongly-connected-components.html
// C++ code to solve the 'Strong connectivity Augmentation problem'

#include <bits/stdc++.h>
using namespace std;

#define MAX 100010

void dfs(int source,
		vector <int> adj[], 
		vector <vector <int> > &scc, 
		bitset <MAX> &in_stack, 
		vector <int> &dfs_low, 
		vector <int> &dfs_num, 
		vector <int> &scc_stack,
		int &counter) {
	// set the low value and discovered values
	counter ++;
	dfs_num[source] = counter;
	dfs_low[source] = counter;

	// mark source as visited
	in_stack[source] = 1;

	// push source to scc_stack
	scc_stack.push_back(source);

	for (auto v: adj[source]) {
		// v is not visited, i.e. dfs_num is -1
		if (dfs_num[v] == -1) {
			// call dfs on v
			dfs(v, adj, scc, in_stack, dfs_low, dfs_num, scc_stack, counter);
		}
		// update the dfs_low value when v is in_stack
		if (in_stack[v]) {
			dfs_low[source] = min(dfs_low[source], dfs_low[v]);
		}
	}

	// after source has been explored fully,
	// if dfs_low value and dfs_num values are the same
	// source is the root of the current SCC
	vector <int> curr_scc;
	if (dfs_low[source] == dfs_num[source]) {
		int top = scc_stack.back();
		// keep popping from scc_stack and pushing to curr_scc
		while (top != source) {
			curr_scc.push_back(top);
			scc_stack.pop_back();

			// ALSO SET THE DFS_NUM FOR ALL VERTICES IN SAME SCC AS THAT OF ROOT
			dfs_num[top] = dfs_num[source];

			// make sure to mark top as removed from stack
			in_stack[top] = 0;

			// update top
			top = scc_stack.back();
		}
		// pop the source from the scc_stack
		scc_stack.pop_back();
		// push the source to the curr_scc
		curr_scc.push_back(source);
		// mark it removed from the stack
		in_stack[source] = 0;

		// add the current SCC to the result
		scc.push_back(curr_scc);
	}
}

int solve_using_tarjan(int V, vector <int> adj[]) {
	// dfs_low[u] stores the lowest dfs_num reachable from the current
	// dfs subtree of 'u'
	vector <int> dfs_low(V, -1);
	// dfs_num[u] stores the iteration counter when 'u' is visited for the first time
	// dfs_num is also used to check whether a vertex is visited
	vector <int> dfs_num(V, -1);
	// stack used in Tarjan's algorithm
	vector <int> scc_stack;

	// vector of vectors to store the SCCs
	vector <vector <int> > scc;

	// visited bitset to check whether a vertex is in_stack
	bitset <MAX> in_stack;

	// dfs timer
	int timer = 0;
	for (int v = 0; v < V; v ++) {
		if (dfs_num[v] == -1) {
			dfs(v, adj, scc, in_stack, dfs_low, dfs_num, scc_stack, timer);
		}
	}

	// SPECIAL CASE: if only 1 SCC, then no more edges to be added
	if (scc.size() == 1) {
		return 0;
	}

	// find the source and sinks in the SCC meta graph
	// formed by collapsing the vertices in the same SCC
	// the collapsed SCCs are represented by a unique dfs_num value

	// one more size since time(dfs_num) started from 1
	vector <int> in_degree(V + 1, 0), out_degree(V + 1, 0);
	for (int u = 0; u < V; u ++) {
		for (auto v: adj[u]) {
			if (dfs_num[u] != dfs_num[v]) {
				// not in the same scc
				// thus u->v is edge in meta graph
				in_degree[dfs_num[v]] ++;
				out_degree[dfs_num[u]] ++;
			}
		}
	}

	// compute the no. of sources and sinks in the meta graph
	int num_sources = 0, num_sinks = 0;
	for (int scc_idx = 0; scc_idx < scc.size(); scc_idx ++) {
		// compute the root of the scc
		int scc_head = scc[scc_idx].front();
		// compute the visiting time of the scc_head
		int scc_time = dfs_num[scc_head];
		// check the indegree and outdegree stored at this time
		if (in_degree[scc_time] == 0) {
			num_sources ++;
		}
		if (out_degree[scc_time] == 0) {
			num_sinks ++;
		}
	}
	return max(num_sources, num_sinks);
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
			// 0-based indexing
			u --;
			v --;
			adj[u].push_back(v);
		}

		cout << solve_using_tarjan(num_nodes, adj) << endl;
	}
	return 0;
}