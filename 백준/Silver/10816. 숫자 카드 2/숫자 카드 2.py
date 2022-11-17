import sys

input = sys.stdin.readline

N = int(input())

SL = list(map(int, input().split()))

SD = dict()

for x in SL:
    if x not in SD:
        SD[x] = 1
    else:
        SD[x] += 1

M = int(input())

FL = list(map(int, input().split()))

result = []
for x in FL:
    try:
        result.append(SD[x])
    except:
        result.append(0)

print(*result)