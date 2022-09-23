import sys

input = sys.stdin.readline

N = int(input())
L = []
for i in range(N):
    line = input().split()
    if line[0] == 'push_front':
        L.insert(0, line[1])
    elif line[0] == 'push_back':
        L.append(line[1])
    elif line[0] == 'pop_front':
        if len(L) != 0:
            print(L.pop(0))
        else:
            print(-1)
    elif line[0] == 'pop_back':
        if len(L) != 0:
            print(L.pop())
        else:
            print(-1)
    elif line[0] == 'size':
        print(len(L))
    elif line[0] == 'empty':
        if len(L) != 0:
            print(0)
        else:
            print(1)
    elif line[0] == 'front':
        if len(L) != 0:
            print(L[0])
        else:
            print(-1)
    elif line[0] == 'back':
        if len(L) != 0:
            print(L[-1])
        else:
            print(-1)