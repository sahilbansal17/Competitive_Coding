#The diameter of a tree is the length of the path (as number of nodes) between the 2 most distant leaves.
#
#A solution that may quickly come to mind is to initiate a breadth-first search from every node and remember the maximum distance.
#However, this approach has an O(n^2) time complexity, which is not the optimal runtime for this task.
#
#We can think of a better solutin:
#    - let's suppose that U is the last node discovered after a BFS from an arbitrary node (let it be 1)
#    - we are now in a "corner" (we can't go any deeper in the tree or any more to the left or right.)
#    - so, if we run a BFS again from U, the last node we discover, let it be V, will be in the other extremity of the tree
#    - with all that said, the diameter of the tree will be the distance between U and V.
#
#The algorithm above has an O(n) time complexity if implemented using adjancency lists.
#
#Test data:
#
# n = 2
# m = 1
# 1 2
#n = 11
# m = 10
#1 2
#1 3
#1 4
#2 5
#3 6
#4 7
#5 8
#5 9
#6 10
#10 11
from collections import defaultdict, deque

last = 0
lMax = 0
def bfs(start):
    global last, lMax
    dist = [-1] * (N+1)
    dist[start] = 0
    queue = deque([start])
    while(queue):
        current = queue.popleft()
        for i in V[current]:
            if dist[i] == -1:
                dist[i] = dist[current] + 1
                queue.append(i)
                last = i
                lMax = dist[i]



N = int(input("Give the number of vertices (N): "))
M = int(input("Give the number of edges (M): "))

V = defaultdict(list)

for i in range(M):
    x = int(input("First vertex: "))
    y = int(input("Second vertex: "))

    V[x].append(y)

bfs(1)
bfs(last)

print("The diameter of the tree is {}".format(lMax))
