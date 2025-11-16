import sys
from collections import deque
input = sys.stdin.readline

n, m, r = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)


def dfs(v, v_dfs=[]):
    v_dfs.append(v)
    graph[v].sort()
    for i in graph[v]:
        if not i in v_dfs:
            v_dfs = dfs(i, v_dfs)
    return v_dfs


que = deque()
v_bfs = []
def bfs(v):
    v_bfs.append(v)
    que.append(v)
    while(len(que) > 0):
        v = que.popleft()
        graph[v].sort()
        for i in graph[v]:
            if not i in v_bfs:
                v_bfs.append(i)
                que.append(i)
bfs(r)
for x in dfs(r):
    print(x, end=' ')
print()
for x in v_bfs:
    print(x, end=' ')