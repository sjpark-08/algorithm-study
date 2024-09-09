import sys
input = sys.stdin.readline
N, K = map(int, input().split())
arr = list(map(int, input().split()))
cnt = [0 for _ in range(100001)]
left = right = 0
ans = 1
cnt[arr[left]] += 1
while right < N - 1:
    right += 1
    cnt[arr[right]] += 1
    while cnt[arr[right]] > K:
        cnt[arr[left]] -= 1
        left += 1
    ans = max(ans, right - left + 1)
print(ans)