'''
Suppose we have a weighted graph with N edges and M vertices.
We need to find the shortest path from node X to node Y.

One simple approach is to generate any possible path and see which one is the shortest. However, this approach is exponential in terms of time and becomes virtually useless when N and M tend to get larger.
The efficient approach is called Dijkstra's Algorithm (https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
The functionality of the algorithm is very BFS-like, but instead of picking the first node in the queue every time we will be looking at the node with the minimal cost that we haven't visited yet.

The running time of the algorithm depends on the way in which we extract the minimum cost node:
    - O(N + M^2), if we use a regular array/linked list
    - O(N + M * log M), if we extract the minimum by using a priority queue (or any other structure with logarithmic insertion/deletion times)

Below we can find an implementation using Python's PriorityQueue on directed graphs, but the algorithm can be extended to undirected graphs.
Test data:
N = 5
M = 6
X = 1
Y = 3
first node, last node, weight:
1 2 1
1 4 2
4 3 4
2 3 2
4 5 3
3 5 6

Distance is 3
'''
from queue import PriorityQueue
from collections import defaultdict

N = int(input("Give the number of vertices (N): "))
M = int(input("Give the number of edges (M): "))
X = int(input("Give node X: "))
Y = int(input("Give node Y: "))
V = defaultdict(list)
oo = 1 << 25
class edge:
    v = 0
    w = 0

    def __init__(self, v, w):
        self.v = v
        self.w = w

def dijkstra(start, finish):
    pq = PriorityQueue()

    dist = [oo] * (N+1)
    visited = [0] * (N+1)
    dist[start] = 0
    pq.put((0, start))

    while pq and dist[finish] == oo:
        u = pq.get()[1]
        if(visited[u]):
            continue
        for i in V[u]:
            v = i.v
            w = i.w
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                pq.put((dist[v], v))
        visited[u] = 1
    return dist[finish]


for i in range(M):
    a = int(input("first node: "))
    V[a].append(edge(int(input("second node: ")), int(input("weight: "))))

print("Distance is ", dijkstra(X, Y), sep='')
