// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

// C++ program to find out whether a given graph is bipartite or not
// using BFS
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
bool isBipartite(int G[][MAX], int V);

bool checkComponentBipartite(int G[][MAX], int V, int node, vector <int> &colors);

int main() {

    int t;
    cin >> t;

    int g[MAX][MAX];
    while (t --) {
        memset(g, 0, sizeof(g));
        int n;
        cin >> n;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cin >> g[i][j];
            }
        }
        cout << isBipartite(g, n) << endl;
    }
    return 0;
}

bool checkComponentBipartite(int G[][MAX], int V, int node, vector <int> &colors) {
    queue <int> q;
    q.push(node);
    int color = 0;
    colors[node] = color;
    while (!q.empty()) {
        int top_node = q.front();
        color = colors[top_node];
        for (int next = 0; next < V; next ++) {
            if (G[top_node][next] == 1 && colors[next] == -1) {
                colors[next] = color ^ 1;
                q.push(next);
            }
            else if (G[top_node][next] == 1 && colors[next] != -1) {
                if (colors[next] == color) {
                    return 0;
                }
            }
        }
        q.pop();
    }
    return 1;
}

bool isBipartite(int G[][MAX],int V)
{
    vector <bool> visited(V, 0);
    queue <int> q;
    bool res = 1;
    vector <int> colors(V, -1);
    for (int i = 0; i < V; i ++) {
        if (colors[i] == -1) {
            res = res & checkComponentBipartite(G, V, i, colors);
        }
    }
    return res;
}