# We are given an directed acyclic graph with N vertices and M edges. Determine one topological ordering of the graph
# ! topological sorting/ordering = a linear ordering of the vertices of a Directed Acyclic Graph (important!) so that for any nodes i & j if there exists an arrow/directed arc (i, j),
#                                  i comes before j.
# ! this is not unique
# 
# This task can be easily achieved by a slight modification of the DFS algorithm.
# We will use a stack to append a node after we are done with visiting its neighbours, and then we will print it reversed.

from collections import defaultdict

def dfs(start):
    vis[start] = True
    for i in V[start]:
        if vis[i] == False:
            dfs(i)
    top_sort.append(start)

N = int(input("Give the number of vertices (N): "))
M = int(input("Give the number of edges (M): "))

vis = [False] * (N+1)
V = defaultdict(list)
top_sort = []

for i in range(M):
    x = int(input("First vertex: "))
    y = int(input("Second vertex: "))
    V[x].append(y)

for i in range(1, N+1):
    if vis[i] == False:
        dfs(i)

print(top_sort[::-1])
