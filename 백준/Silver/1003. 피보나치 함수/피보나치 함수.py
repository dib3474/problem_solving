import sys

input = sys.stdin.readline

T = int(input())

A = [1,0]
B = [0,1]

for i in range(2, 41):
    A.append(A[i-2] + A[i-1])

for i in range(2, 41):
    B.append(B[i-2] + B[i-1])

for _ in range(T):
    N = int(input())
    print(A[N], B[N])