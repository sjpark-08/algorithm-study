import sys
input = sys.stdin.readline
N = int(input())
board = []
dp = [[0 for _ in range(N)] for _ in range(N)]
for _ in range(N): 
    board.append(list(map(int, input().split())))
dp[0][0] = 1
for i in range(N):
    for j in range(N):
        move = board[i][j]
        if move == 0: continue
        if i + move < N:
            dp[i + move][j] += dp[i][j]
        if j + move < N:
            dp[i][j + move] += dp[i][j]
print(dp[N - 1][N - 1])