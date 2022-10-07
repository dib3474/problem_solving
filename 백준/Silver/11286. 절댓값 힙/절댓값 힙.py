import sys
from queue import PriorityQueue

input = sys.stdin.readline

N = int(input())

que = PriorityQueue()

for _ in range(N):
    tmp = int(input())
    num = (abs(tmp), tmp)
    if tmp != 0:
        que.put(num)
    else:
        if que.empty():
            print(0)
        else:
            print(que.get()[1])