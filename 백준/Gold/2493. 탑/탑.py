import sys
input = sys.stdin.readline
maxval = 100000001
top = 0

stack = [0 for _ in range(500002)]
# tower = [0 for _ in range(500002)]
stack[0] = 0
N = int(input())
tower = list(map(int, input().split()))
tower.insert(0, maxval)
for i in range(1, N + 1):
    while(tower[stack[top]] < tower[i]):
        top -= 1
    print(stack[top], end=' ')
    top += 1
    stack[top] = i
