/**
Suppose we have a theoretical complete infinite tree and we want to traverse it in order to find the closest node to the root with a particular property (which surely exists).
In this case, because the tree is infinite, classic Depth First Search or Breadth First Search won't do the trick.
On a finite tree, we know that BFS would provide the closest node at the cost of larger memory than DFS ( O(N) where N is the number of nodes in the tree instead of O(D) where D is the depth of the tree)
That's because the lower levels of the tree can have n/2 nodes and we need all of them in the queue at some point in time.
So, DFS is more memory efficient, but BFS provides the smallest distance in term of nodes.

Iterative deepening depth first search (IDDFS) combines the memory efficiency of DFS with the closest-to-root result of BFS and can be suited for infinite (or very big) search trees (especially used in Artificial Intelligence)
It searches the tree using the following approach:
    - it runs a depth first search starting from the root which stops at depth 1
        * if it has found the node, it ends
        * if not, it repeats the process, starting from the root again but stopping at depth 2
    - if increments the depth each time (with depth 2, 3, 4, ...) until it has found the node it was searching for.

Asimptotically, IDDFS has the same time complexity as DFS and BFS, but obviously has a larger constant due to running DFS multiple times.

Some interesting applications can include possible optimisations of some backtracking algorithms.
Take solving a rubik's cube as an example: with BFS (putting configurations in the queue), the queue can get extremely large and a DFS (backtracking) is not sure to give us the solution with the minimum number of nodes.
In general, it also holds an advantage in various game trees.
I will let the implementation of a rubik's cube solver as an exercise as the operations needed to move the rubik's cube faces can get quite long and somehow hard to explain.
Below you can find an implementation of IDDFS which finds the distance between node 1 and some other node n in a tree.
The following example is only to illustrate the implementation of the algorithm and I don't know how practical it is :)
n = 10
m = 9
k = 7 - searched node
1 2
1 8
1 10
2 4
2 3
2 5
5 6
5 7
8 9

answer: 3 (when counting edges)
**/


#include <bits/stdc++.h>
using namespace std;

const int NMAX = (1 << 10);

vector<int> A[NMAX];
bitset<NMAX> V;
int maxDepth, depth;


void dfs(int x) {
    for(const auto& i: A[x])
        if(V[i] == 0 && depth < maxDepth) {
            depth++;
            V[i] = 1;
            dfs(i);
            depth--;
        }
}

void search(int n, int k) {
    maxDepth = 1;
    do {
        V.reset();
        depth = 0;

        dfs(1);
        maxDepth++;
    } while(V[k] == 0);

    cout << maxDepth-1; /// the interesting think is that we don't need a distance array -> the max depth to which we searched is the distance.
}

int main() {
    int n, m, k;
    cout << "number of nodes = "; cin >> n;
    cout << "number of edges = "; cin >> m;
    cout << "node to search for = "; cin >> k;
    int x, y;
    while(m--) {
        cout << "x y: "; cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }

    search(n, k);
}
