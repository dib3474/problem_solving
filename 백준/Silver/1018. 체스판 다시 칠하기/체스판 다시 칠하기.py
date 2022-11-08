import sys
input = sys.stdin.readline

n, m = map(int, input().split())
board = []
for i in range(n):
    board.append(list(input()))

result = 64
for i in range(n-7):
    for j in range(m-7):
        cnt = 0
        for a in range(i, i+8):
            for b in range(j, j+8):
                if (a+b)%2==0:
                    if board[a][b] == 'B':
                        cnt += 1
                else:
                    if board[a][b] == 'W':
                        cnt += 1
        if cnt > 32:
            cnt = 64 - cnt
        result = min(result, cnt)

print(result)