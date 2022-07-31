from functools import cmp_to_key
t = int(input())


def mycmp(a, b):
  if a[0] > b[0]:
    return 1
  elif a[0] < b[0]:
    return -1
  return 0

for i in range(t):
  n, m = map(int, input().split())
  a = list(map(int, input().split()))
  
  adj = [0] * n
  for j in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    if adj[x] == 0:
      adj[x] = set()
    if adj[y] == 0:
      adj[y] = set()
    adj[x].add(y)
    adj[y].add(x)

  b = []
  for j in range(len(a)):
    b.append((a[j], j))
  
  # sort the list of tuples b
  b.sort(key=cmp_to_key(mycmp))
  
  if m % 2 == 0:
    print(0)
  else:
    idx = 0
    res = 0
    while (m > 0 and m % 2 == 1):
      cur = b[idx]
      vert = cur[1]
      if adj[vert] == 0:
        idx += 1
        continue
      res += cur[0]
      for nxt in adj[vert]:
        adj[nxt].remove(vert)
        m -= 1
      idx += 1
    print(res)
