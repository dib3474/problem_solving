import sys
input = sys.stdin.readline

n = int(input())

graph = []

for _ in range(n):
    graph.append([i for i, x in enumerate(list(map(int, input().split()))) if x == 1])
        
def dfs(v, visited = []):
    global cnt
    if cnt >= 1: visited.append(v)
    for i in graph[v]:
        if not i in visited:
            cnt += 1
            visited = dfs(i, visited)
    return visited

tmp = []
for i in range(n):
    cnt = 0
    tmp.append(dfs(i, []))
for i in range(n):
    for j in range(n):
        if j in tmp[i]:
            print(1, end=' ')
        else:
            print(0, end=' ')
    print()