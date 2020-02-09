'''
A bipartite graph is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V.
The 2 sets are usually called parts of the graph.

We are given a graph with N nodes and M edges and we have to determine if it is bipartite.

The definition implies that the graph should be connected (if it weren't, then we couldn't form the 2 sets).
So we have to take that into account when checking whether a graph is bipartite or not. (*)

The problem can be very easily solved by observing a simple fact: we can determine sets U and V ourselves by colouring the graph.
How can we do such a colouring:
    1) we start a breadth-first search from an arbitrary node (let it be 1)
    2) we colour node 1 with say, blue, then proceed to colour its adjacent nodes with red.
    3) when we reach a node k, we colour the adjacent nodes as following:
        - blue, if k is coloured red.
        - red, if k is coloured blue.
    4) if we find any already-coloured neighbour which doesn't fit the colour scheme we're trying to make (that no 2 blue and no 2 red nodes can be adjacent), then the graph is not bipartite.
    5) if we haven't found any node at 4), from the observation (*) I made above, we still have to check if the graph is connected.
        we can easily do this by counting the number of nodes we have coloured - if the graph is connected, then at the end of the BFS we should have coloured exactly N nodes.
The code below implements the idea for an unoriented graph.

'''
from collections import defaultdict, deque


BLUE = 1
RED = 2

def bipartite(start):
    queue = deque([start])
    col_nodes = 1
    col[start] = BLUE
    while(queue and col_nodes != -1):
        current = queue.popleft()
        adj_col = BLUE if col[current] == RED else RED
        for i in V[current]:
            if col[i] == 0:
                col[i] = adj_col
                queue.append(i)
                col_nodes += 1
            elif col[i] == col[current]:
                col_nodes = -1
    print(col_nodes)
    return (True if col_nodes == N else False)


N = int(input("Give the number of vertices (N): "))
M = int(input("Give the number of edges (M): "))

col = [0] * (N+1)
col_nodes = 0
V = defaultdict(list)

for i in range(M):
    x = int(input("First vertex: "))
    y = int(input("Second vertex: "))

    V[x].append(y)
    V[y].append(x)

result = bipartite(1)

print("The graph is bipartite." if result else "The graph is not bipartite.")
