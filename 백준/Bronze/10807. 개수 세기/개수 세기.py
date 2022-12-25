import sys
input = sys.stdin.readline

n = input()

L = list(map(int, input().split()))

v = int(input())
print(L.count(v))