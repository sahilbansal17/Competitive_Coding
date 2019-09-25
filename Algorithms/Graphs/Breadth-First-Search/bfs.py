# We are given an directed graph with N vertices and M edges and a node X.
# Print the minimum distance between node X and all the other nodes.
# ! minimum distance between nodes A and B = the smallest elementary path that unites the 2 nodes;
#                                            -1 if there is none
#                                            0 if A = B
#
# The problem can easily be solved by a classic Breadth-First Search algorithm.
# In case of a graph, The Breadth-First Search starts with an arbitrary node and explores all of the neighbours at present level before moving on to the next level.
# The implementation below uses the defaultdict and deque classes from the Python standard library.
# The main difference between defaultdict and "normal" dictionaries is that if you try to access a key which is not currently in the dictionary it simply creates it instead of throwing an exception.
# deques support efficient appends and pops from either sides (approximately O(1)).

from collections import defaultdict, deque

def bfs(start):
    queue = deque([start])
    while(queue):
        current = queue.popleft()
        for i in V[current]:
            if dist[i] == -1:
                dist[i] = dist[current] + 1
                queue.append(i)


N = int(input("Give the number of vertices (N): "))
M = int(input("Give the number of edges (M): "))
X = int(input("Give the start node (X): "))

dist = [-1] * (N+1)
dist[X] = 0
V = defaultdict(list)

for i in range(M):
    x = int(input("First vertex: "))
    y = int(input("Second vertex: "))

    V[x].append(y)

bfs(X)

for i in range(1, N+1):
    print(i, ": ", dist[i])
