import sys
import math

input = sys.stdin.readline

n = int(input())

m = int(input())

x = list(map(int, input().split()))

gap = 0
for i in range(len(x)-1):
    if x[i+1]-x[i] > gap:
        gap = x[i+1]-x[i]
if gap%2 == 0:
    gap = gap//2
else:
    gap = gap//2 + 1

start = x[0] - 0
end = n - x[-1]
result = [start, end, gap]

print(max(result))