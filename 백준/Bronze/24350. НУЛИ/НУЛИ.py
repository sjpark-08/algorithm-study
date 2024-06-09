import sys
input = sys.stdin.readline
N, K = map(int, input().split())
fac = [1 for _ in range(1001)]

for i in range(2, 1001):
    fac[i] = fac[i - 1] * i
result = fac[N] // (fac[K] * fac[N - K])
cnt = 0
while result > 0:
    if result % 10 == 0:
        cnt += 1
    result //= 10
print(cnt)