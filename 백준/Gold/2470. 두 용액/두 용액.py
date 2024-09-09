import sys
input = sys.stdin.readline
N = int(input())
arr = list(map(int, input().split()))
arr = sorted(arr)
ansL = left = 0
ansR = right = N - 1
ans = 12345678901
while left < right:
    tmp = arr[left] + arr[right]
    if ans > abs(tmp):
        ans = abs(tmp)
        ansL = left
        ansR = right
    if tmp > 0: right -= 1
    elif tmp < 0: left += 1
    else: break
print(arr[ansL], arr[ansR])