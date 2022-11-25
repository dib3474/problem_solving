import sys
input = sys.stdin.readline

result = set()
for _ in range(10):
    result.add(int(input())%42)

print(len(result))