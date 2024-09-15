import sys
input = sys.stdin.readline

inp = input().split()
N = int(inp[0])
K = 0
if inp[1] == "Y": K = 2
elif inp[1] == "F": K = 3
else: K = 4
p = set()
for _ in range(N):
    p.add(str(input().strip()))
K -= 1
print(len(p) // K)