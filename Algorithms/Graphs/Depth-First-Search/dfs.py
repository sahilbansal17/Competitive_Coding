# We are given an undirected graph with N vertices and M edges. Print all its connected components.
# ! connected component = a subgraph in which any two vertices are connected by paths.
#
# This task is fairly easy and can either be achieved by a Depth-First Search (DFS) or a Breadth-First Search (BFS) on the given graph.
# Below, we will discuss the DFS approach.
# In case of a graph, DFS starts from an arbitrary node and explores all adjacent nodes recursively until there is no node to explore.
# Alternatively, we can visualise virtually all backtracking algorithms as DFSs in a graph of states.
#
# The implementation below uses the defaultdict class from the Python standard library.
# The main difference between defaultdict and "normal" dictionaries is that if you try to access a key which is not currently in the dictionary it simply creates it instead of throwing an exception.

from collections import defaultdict

def dfs(start):
    vis[start] = True
    for i in V[start]:
        if vis[i] == False:
            dfs(i)


N = int(input("Give the number of vertices (N): "))
M = int(input("Give the number of edges (M): "))

vis = [False] * (N+1)
V = defaultdict(list)

for i in range(M):
    x = int(input("First vertex: "))
    y = int(input("Second vertex: "))

    V[x].append(y)
    V[y].append(x)

connected_components = 0

for i in range(1, N+1):
    if vis[i] == False:
        dfs(i)
        connected_components += 1

print("There are " + str(connected_components) + " connected components in the given graph")
