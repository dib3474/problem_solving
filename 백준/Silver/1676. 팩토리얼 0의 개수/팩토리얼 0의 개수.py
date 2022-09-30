import sys
import math

N = list(str(math.factorial(int(sys.stdin.readline()))))
i = -1
zcnt = 0
while(1):
    if N[i] == '0':
        zcnt += 1
        i -= 1
    else:
        break

print(zcnt)