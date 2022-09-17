import sys

x, y, w, h = map(int, input().split())

if y > h/2:  a = h - y
else:        a = y

if x > w/2:  b = w - x
else:        b = x

print(min(a, b))