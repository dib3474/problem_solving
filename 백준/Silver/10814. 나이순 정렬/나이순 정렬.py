import sys

N = int(sys.stdin.readline())

L = []
for i in range(N):
    a, b = sys.stdin.readline().strip('\n').split()
    L.append([int(a), b])

L.sort(key=lambda x:x[0])

for x in L:
    print(*x)