import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):

    func = list(input().rstrip())
    n = int(input())
    try:
        L = list(map(int, input().rstrip()[1:-1].split(',')))
    except:
        L = []
        state = 1

    state = 0
    flip = 0

    for x in func:
        if x == 'R':
            flip += 1
        elif x == 'D' and len(L) == 0:
            state = 1
            break
        else:
            if flip%2 == 1:
                L.pop()
            else:
                L.pop(0)


    if flip%2 == 1:
        L.reverse()

    if state == 0:
        print("[" + ",".join(list(map(str, L))) + "]")
    else:
        print('error')
