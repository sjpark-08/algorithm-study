import sys
input = sys.stdin.readline

A, B = map(int, input().split())
A, B = min(A, B), max(A, B)

if A == B:
    print(0)
else:
    print(B - A - 1)
    ans = ""
    for i in range(A + 1, B):
        print(i, end=" ")
