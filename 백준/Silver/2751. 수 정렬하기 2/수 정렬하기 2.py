import sys

N = int(sys.stdin.readline())

L = []
for _ in range(N):
    L.append(int(sys.stdin.readline()))
L.sort()

for x in L:
    print(x)