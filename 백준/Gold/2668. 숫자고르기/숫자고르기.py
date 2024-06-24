import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
N = int(input())

match = [0]
visited = [False for _ in range(N + 1)]
finished = [False for _ in range(N + 1)]
result = []

def dfs(now):
    global match, visited, finished, result
    visited[now] = True
    next = match[now]

    if not visited[next]: dfs(next)
    elif not finished[next]:
        i = next
        while i != now:
            result.append(i)
            i = match[i]
        result.append(i)
    finished[now] = True

for _ in range(N): match.append(int(input()))
for i in range(1, N + 1):
    if visited[i]: continue
    dfs(i)

result = sorted(result)
cnt = 0
ans = []
for x in result:
    cnt += 1
    ans.append(str(x))
print(cnt)
print('\n'.join(ans))