import sys

n = int(sys.stdin.readline())
m = 0
result = ""
stack = []
for i in range(n):
    x = int(sys.stdin.readline())
    if x > m:
        while(x > m):
            m += 1
            stack.append(m)
            result += "+"
        stack.pop()
        result += "-"
    else:
        found = False
        if len(stack) != 0:
            if x == stack.pop():
                result += "-"
                found = True
        if not found:
            print("NO")
            sys.exit()

for x in result:
    print(x)