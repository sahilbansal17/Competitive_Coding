// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0/
// https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

/*  C++ code to implement Floyd Warshall's algorithm
*   to find all pairs shortest path
*   i.e. shortest distance between every pair of vertices in weighted graph
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define INF 10000000
typedef long long ll;

/*  Function to check whether choosing the vertex k as intermediate
*   allows a smaller path between u and v
*/
bool distance_check(ll dist_u_k, ll dist_k_v, ll dist_u_v) {
    if (dist_u_v > dist_u_k + dist_k_v) {
        return true;
    }
    return false;
}

/*  Floyd Warshall function to find all pairs shortest path
*   v = number of vertices
*   adj = adjacency matrix
*/
void floyd_warshall(int v, ll adj[][MAX]) {

    // dist matrix to store all pairs shortest paths
    ll dist[v][v];

    // initialize the dist matrix with initial edge weights
    for (int i = 0; i < v; i ++) {
        for (int j = 0; j < v; j ++) {
            dist[i][j] = adj[i][j];
        }
    }

    // allow k as intermediate vertex after every iteration
    for (int k = 0; k < v; k ++) {
        // dist stores shortest distance between all pairs
        // including only intermediate vertices from 0 to k - 1

        // consider all the pairs (source: i , dest: j)
        for (int i = 0; i < v; i ++) {
            for (int j = 0; j < v; j ++) {
                // using k as intermediate vertex, check if reduces distance
                if (distance_check(dist[i][k], dist[k][j], dist[i][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    } 

    // print the shortest distances
    for (int i = 0; i < v; i ++) {
        for (int j = 0; j < v; j ++) {
            if (dist[i][j] == INF) {
                cout << "INF" << " ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main () {

    int t;
    cin >> t;

    int v;
    while (t --) {
        cin >> v;

        ll adj_matrix[v][MAX];
        string s;
        for (int i = 0; i < v; i ++) {
            for (int j = 0; j < v; j ++) {
                cin >> s;
                if (isdigit(s[0])) {
                    adj_matrix[i][j] = atoi(s.c_str());
                }
                else {
                    adj_matrix[i][j] = INF;
                }
            }
        }

        floyd_warshall(v, adj_matrix);
    }

    return 0;
}