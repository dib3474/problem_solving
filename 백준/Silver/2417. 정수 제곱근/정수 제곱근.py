import sys
input = sys.stdin.readline

N = int(input())

low = 0
high = N
while True:
    mid = (low+high)//2
    if low == mid or high == mid:
        if mid*mid < N:
            mid += 1
        break
    if mid*mid > N:
        high = mid
    else:
        low = mid
    
print(mid)