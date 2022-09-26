import sys

input = sys.stdin.readline

D = list(map(int, input().split()))

C = [1,1,2,2,2,8]

for i in range(len(C)):
    C[i] -= D[i]

for x in C:
    print(x, end=' ')