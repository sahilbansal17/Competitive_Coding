'''
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
'''
from collections import defaultdict

N = int(input("Give the number of vertices (N): "))
M = int(input("Give the number of edges (M): "))
K = int(input("Give the node to search for (K): "))

vis = [False] * (N+1)
V = defaultdict(list)

def dfs(start, depth):
    global vis
    vis[start] = True
    for i in V[start]:
        if vis[i] == False and depth < maxDepth:
            vis[i] = True
            dfs(i, depth+1)



for i in range(M):
    x = int(input("First vertex: "))
    y = int(input("Second vertex: "))

    V[x].append(y)
    V[y].append(x)

maxDepth = 1

while True:
    vis = [False] * (N+1)
    vis[1] = True

    dfs(1, 0)
    if vis[K] == True:
        break
    maxDepth += 1


print(maxDepth)
