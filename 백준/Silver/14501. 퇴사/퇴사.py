import sys
input = sys.stdin.readline

n = int(input())

s = [0]
for _ in range(n):
    s.append(list(map(int, input().split())))
    
d = [0 for _ in range(n+2)]

for i in range(1, n+1):
    if i + s[i][0] <= n+1:
        d[i + s[i][0]] = max(d[i] + s[i][1], d[i + s[i][0]])
        for j in range(i+s[i][0], n+1):
            d[j] = max(d[i + s[i][0]], d[j])

print(max(d))