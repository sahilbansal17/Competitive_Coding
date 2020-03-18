'''
We are given a weighted undirected connected graph with N nodes and M edges.
We have to determine a subgraph which is a tree and the sum of the weights of the edges (from now on called the cost of the tree) is minimal. This is called a minimum spanning tree.

One obvious solution is to try every possible tree and find the one with the minimum cost.
However, this solution's complexity is exponential.

One efficient solution follows a constructive greedy approach by making a simple remark: suppose we were to only add the first N-1 cheapest edges which don't form any cycles - could have we got a cheaper tree?
Well, we couldn't have - we already had the cheapest possible edge selection.

Now, let's make a short description of what the algorithm should do in order to achieve that node selection:
    - sort the edges by their weight (so we will have the cheapest edges first)
    - loop through all edges while the number of added edges doesn't reach N-1:
        -- if the current edge forms a cycle, we continue
        -- if the current edge doesn't form a cycle, we add it to the spanning tree and mark the two extremities as beign in the same connected component.

In order to efficiently represent and merge the connected components, we should use disjoint sets (described here: https://github.com/sahilbansal17/Competitive_Coding/blob/master/Algorithms/Graphs/detect_cycle_union_find_naive.py)
The same idea above is also used for the code below.
'''
N, M = int(input("Give the number of vertices (N): ")), int(input("Give the number of edges (M): "))
P = [i for i in range(0, N+1)]
E = []

class edge:
    def __init__(self, x, y, w):
        self.x, self.y, self.w = x, y, w

    def __lt__(self, other):
        return self.w < other.w

def find(x): # find the parent
    global P
    if P[x] == x:
        return x
    else:
        P[x] = find(P[x])
        return P[x]

for i in range(M):
    E.append(edge(int(input("x: ")), int(input("y: ")), int(input("w: "))))
E.sort()

added_edges, current_edge, total_cost, edge_list = 0, 0, 0, []
while added_edges < N-1 and current_edge < M:
    p_x, p_y = find(E[current_edge].x), find(E[current_edge].y)

    if p_x != p_y:
        edge_list.append(current_edge)
        P[p_x] = P[p_y]
        total_cost += E[current_edge].w
        added_edges += 1

    current_edge += 1

print("total cost: ", total_cost)
for i in edge_list:
    print(E[i].x, ' ', E[i].y, ' ', E[i].w)
