import sys
import copy
input = sys.stdin.readline

N = int(input())

player = []
for i in range(N):
    a,b,c = map(int, input().split())
    player.append([a,b,c])

result = copy.deepcopy(player)
for i in range(3):
    for j in range(N):
        for k in range(N):
            if j != k and player[j][i] == player[k][i]:
                result[j][i] = 0

for x in result:
    print(sum(x))
