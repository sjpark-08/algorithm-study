import collections
import sys
input = sys.stdin.readline

dx = (0, 0, -1, 1)
dy = (-1, 1, 0, 0)

def bfsFire():
    while fQ:
        x, y = fQ.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if not (0 <= nx < R and 0 <= ny < C): continue
            if visitFire[nx][ny] or map[nx][ny] == '#': continue
            visitFire[nx][ny] = visitFire[x][y] + 1
            fQ.append([nx, ny])

def bfs():
    while hQ:
        x, y = hQ.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if not (0 <= nx < R and 0 <= ny < C):
                print(visit[x][y])
                return
            if visit[nx][ny] or map[nx][ny] == '#': continue
            if visitFire[nx][ny] and visitFire[nx][ny] <= visit[x][y] + 1: continue
            visit[nx][ny] = visit[x][y] + 1
            hQ.append([nx, ny])
    print("IMPOSSIBLE")
    return


R, C = map(int, input().split())
visit = [[0 for _ in range(C)] for _ in range(R)]
visitFire = [[0 for _ in range(C)] for _ in range(R)]
map = []

fQ = collections.deque()
hQ = collections.deque() 

for i in range(R):
    map.append(list(input().strip()))

for i in range(R):
    for j in range(C):
        if map[i][j] == 'F':
            fQ.append([i, j])
            visitFire[i][j] = 1
        elif map[i][j] == 'J':
            hQ.append([i, j])
            visit[i][j] = 1
bfsFire()
bfs()
