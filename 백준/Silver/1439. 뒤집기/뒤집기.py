import sys
input = sys.stdin.readline

s = list(input().rstrip())

start = s[0]
flag = True
cnt = 0
for i in range(1, len(s)):
    if s[i] != start:
        flag = False
    elif not flag:
        cnt += 1
        flag = True
    if i == len(s)-1 and not flag:
        cnt += 1

print(cnt)