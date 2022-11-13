import sys
input = sys.stdin.readline

n = int(input())
students = []
for _ in range(n):
    students.append(list(input().rstrip()))
for i in range(len(students[0])-1, -1, -1):
    tmp = set()
    for x in students:
        tmp.add(str(x[i:]))
    if len(tmp) == n:
        print(len(students[0])-i)
        break