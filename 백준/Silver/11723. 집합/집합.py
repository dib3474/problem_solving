import sys

input = sys.stdin.readline

M = int(input())

S = set()
for _ in range(M):
    cmd = input().split()
    if len(cmd) > 1:
        cmd[1] = int(cmd[1])
    if cmd[0] == 'add':
        S.add(cmd[1])
    elif cmd[0] == 'remove':
        S.discard(cmd[1])
    elif cmd[0] == 'check':
        print(int(cmd[1] in S))
    elif cmd[0] == 'toggle':
        if cmd[1] in S:
            S.remove(cmd[1])
        else:
            S.add(cmd[1])
    elif cmd[0] == 'all':
        S = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}
    elif cmd[0] == 'empty':
        S = set()
