import sys

input = sys.stdin.readline

N, M = map(int, input().split())

sitelist = {}
for _ in range(N):
    site, pwd = input().split()
    sitelist[site] = pwd

for _ in range(M):
    print(sitelist[input().rstrip()])