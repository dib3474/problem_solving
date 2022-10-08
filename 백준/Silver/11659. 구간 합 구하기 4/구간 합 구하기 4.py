import sys

input = sys.stdin.readline

N, M = map(int, input().split())

L = list(map(int, input().split()))

Sum = 0
Sum_list = [0]
for i in L:
    Sum += i
    Sum_list.append(Sum)

for _ in range(M):
    x, y = map(int, input().split())
    result = Sum_list[y] - Sum_list[x-1]
    print(result)