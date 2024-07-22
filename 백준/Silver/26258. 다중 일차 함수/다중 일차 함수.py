import bisect
import sys
input = sys.stdin.readline
X = []
Y = []

N = int(input())
for i in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)

Q = int(input())
for i in range(Q):
    c = float(input())
    left = bisect.bisect_left(X, c)
    right = bisect.bisect_right(X, c)

    if left == right:
        left -= 1
    if Y[right] - Y[left] > 0:
        print(1)
    elif Y[right] - Y[left] < 0:
        print(-1)
    else:
        print(0)