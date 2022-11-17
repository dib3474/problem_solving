import sys

input = sys.stdin.readline

n, m = map(int, input().split())

trees = list(map(int, input().split()))

start, end = 0, max(trees)

while(start <= end):
    mid = (start+end)//2
    cut = 0
    for x in trees:
        if x > mid:
            cut += x - mid
    if cut >= m:
        start = mid + 1
    else:
        end = mid - 1
print(end)