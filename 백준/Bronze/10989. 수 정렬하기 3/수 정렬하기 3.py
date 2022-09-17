import sys

N = int(sys.stdin.readline())

L = [0]*10000
for _ in range(N):
    L[int(sys.stdin.readline())-1] += 1

for i, x in enumerate(L):
    if x != 0:
        for _ in range(x):
            print(i+1)