/**
The diameter of a tree is the length of the path (as number of nodes) between the 2 most distant leaves.

A solution that may quickly come to mind is to initiate a breadth-first search from every node and remember the maximum distance.
However, this approach has an O(n^2) time complexity, which is not the optimal runtime for this task.

We can think of a better solutin:
    - let's suppose that U is the last node discovered after a BFS from an arbitrary node (let it be 1)
    - we are now in a "corner" (we can't go any deeper in the tree or any more to the left or right.)
    - so, if we run a BFS again from U, the last node we discover, let it be V, will be in the other extremity of the tree
    - with all that said, the diameter of the tree will be the distance between U and V.

The algorithm above has an O(n) time complexity if implemented using adjancency lists.

Test data:

n = 11
m = 10
1 2
1 3
1 4
2 5
3 6
4 7
5 8
5 9
6 10
10 11

Result: 8
**/
#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100000;

vector<int> A[NMAX];
queue<int> C;
int d[NMAX],
    lMax, lst, n, m;

void bfs(int x) {
    C.push(x);
    d[x] = 1;
    int crt = 0;
    while(!C.empty()) {
        crt = C.front();
        C.pop();

        for(auto i: A[crt])
            if(d[i] == 0) {
                d[i] = d[crt]+1;
                lst = i;
                lMax = d[i];
                C.push(i);
            }
    }
    for(int i = 1; i <= n; i++)
        d[i] = 0;
}

int main()
{
    int x, y;
    cout << "Give the number of nodes: "; cin >> n;
    cout << "Give the number of edges:"; cin >> m;
    while(m--) {
        cout << "x y: "; cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }

    bfs(1);
    bfs(lst);

    cout << "The diameter of the tree is " << lMax << ".";
    return 0;
}
