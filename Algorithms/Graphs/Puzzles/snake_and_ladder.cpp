// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
const int START = 1;
const int FINAL = 30;
int moves[MAX];

int getMinimumDiceThrows(int move[]) {
    vector <int> visited(FINAL + 1, 0);
    queue <pair <int, int> > node_distances;
    node_distances.push({START, 0});
    while (!node_distances.empty()) {
        int current_node = node_distances.front().first;
        int current_dist = node_distances.front().second;
        if (current_node == FINAL) {
            // reached the destination
            return current_dist;
        }
        for (int dice_val = 1; dice_val <= 6; dice_val ++) {
            int next_node = current_node + dice_val;
            if (!visited[next_node]) {
                if (moves[next_node] != -1) {
                    next_node = moves[next_node];
                }
                int next_distance = current_dist + 1;
                node_distances.push({next_node, next_distance});
            }
        }
        visited[current_node] = 1;
        node_distances.pop();
    }
    return -1;
}

int main() {
    
    int t, n, a, b;
    cin >> t;
    
    for (int i = 0; i < t; i ++) {
        cin >> n;
        memset(moves, -1, sizeof(moves));
        for (int j = 0; j < n; j ++) {
            cin >> a >> b;
            moves[a] = b;
        }
        cout << getMinimumDiceThrows(moves) << endl;
    }
    
    return 0;
}