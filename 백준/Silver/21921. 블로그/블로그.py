import sys
input = sys.stdin.readline
N, X = map(int, input().split())
nums = list(map(int, input().split()))

tmp = 0
cnt = 1
for i in range(X): tmp += nums[i]
ans = tmp
left = 0
right = X - 1
while right < N - 1:
    tmp -= nums[left]
    left += 1
    right += 1
    tmp += nums[right]
    if ans < tmp:
        ans = tmp
        cnt = 1
    elif ans == tmp:
        cnt += 1


if ans == 0: print("SAD")
else:
    print(ans)
    print(cnt)