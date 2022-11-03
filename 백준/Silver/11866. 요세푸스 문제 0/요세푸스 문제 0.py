import sys
input = sys.stdin.readline
N, K = map(int, input().split())

L = [i for i in range(1,N+1)]

print("<", end="")
for i in range(N-1):
    for j in range(K-1):
        L.append(L.pop(0))
    print(L.pop(0), end=", ")
print(f"{L.pop(0)}>")