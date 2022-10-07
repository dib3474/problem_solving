import sys
from queue import PriorityQueue

input = sys.stdin.readline

N = int(input())

que = PriorityQueue()

for _ in range(N):
    tmp = int(input())
    if tmp != 0:
        que.put(tmp)
    else:
        if que.empty():
            print(0)
        else:
            print(que.get())