'''
We are given an undirected graph with N nodes and M edges. Our goal is to determine whether the given graph contains any cycles or not.

One obvious solution is to generate all possible paths and determine if any of them can form a cycle.
However, this solution's complexity is exponential and can prove extremely inefficient in practice.


An O(N) solution can be devised, but first we have to introduce a specific data structure: disjoint sets (union-find).
Its job is to keep track of a set of elements partitioned in some number of disjoint subsets. The trick to remember a parent for every element in the set, using a 1-dimensional array.

Now, we can start describing a solution:
    - we start with a graph with no edges (only the N nodes), and for each node i we remember its connected component (let it be P[i]) which at first is i.
    - we read every edge, and:
        (1) if the two extremities are in different connected components, we "merge" the 2 components (i.e. P[parent(i)] = P[parent(j)]).
        (2) if the two extremities are already in the same connected component, then they will form a cycle.
    - the algorithm ends when it reaches (2) or when there are no edges left to read; in the second case, the graph has no cycles.
'''

N, M = int(input("Give the number of vertices (N): ")), int(input("Give the number of edges (M): "))
P = [i for i in range(0, N+1)]
found_cycle = False

def find(x): # find the parent
    global P
    if P[x] == x:
        return x
    else:
        P[x] = find(P[x])
        return P[x]

for i in range (M):
    pA, pB = find(int(input("a: "))), find(int(input("b: ")))

    if pA != pB:
        P[pA] = P[pB]
    else:
        found_cycle = True

print("The graph contains a cycle" if found_cycle else "The graph doesn't contain a cycle")
