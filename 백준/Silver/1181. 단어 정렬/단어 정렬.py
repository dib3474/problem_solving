import sys

N = int(sys.stdin.readline())

string = []
for i in range(N):
    string.append(sys.stdin.readline().strip('\n'))

string = list(set(string))

string.sort(key=lambda x: (len(x), x))

for x in string:
    print(x)