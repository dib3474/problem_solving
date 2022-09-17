import sys

N = int(sys.stdin.readline())

L = []
for _ in range(N):
    L.append(list(map(int, sys.stdin.readline().split())))

L.sort()

for x in L:
    print(*x)