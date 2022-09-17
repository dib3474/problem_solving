import sys
from math import ceil

A, B, V = map(int, sys.stdin.readline().split())

if A > V: 
    day = 1
elif (V-A)%(A-B) == 0:
    day = (V-A)//(A-B) + 1
else:
    day = ceil((V-A)/(A-B))+1

print(day)