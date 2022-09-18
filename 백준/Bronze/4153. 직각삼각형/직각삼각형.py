import sys

while(1):
    line = list(map(int, sys.stdin.readline().split()))
    line.sort()
    a=line[0]; b=line[1]; c=line[2]
    if a==0 and b==0 and c==0:
        break
    A = a**2; B = b**2; C = c**2

    if A + B == C:
        print("right")
    else:
        print("wrong")