import sys

input = sys.stdin.readline
from collections import deque

n, m, k, X = map(int, input().split())

graph = [[] for _ in range(n+1)]
visited = [m+1 for _ in range(n+1)]

for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)

que = deque()

def bfs(v):
    global cnt
    visited[v] = 0
    que.append(v)
    while len(que) > 0:
        v = que.popleft()
        for i in graph[v]:
            if visited[i] == m+1:
                visited[i] = visited[v] + 1
                que.append(i)
cnt = 0
bfs(X)

if not k in visited:
    print(-1)
else:
    for i in range(1, n+1):
        if visited[i] == k:
            print(i)