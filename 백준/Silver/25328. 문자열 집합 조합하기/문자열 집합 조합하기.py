import sys
input = sys.stdin.readline

X = list(input().strip())
Y = list(input().strip())
Z = list(input().strip())
K = int(input())
cur = []
match = dict()

def getCom(depth, idx, strlist):
    if depth == K:
        tmp = "".join(cur)
        if tmp not in match: match[tmp] = 1
        else: match[tmp] += 1
    
    for i in range(idx, len(strlist)):
        cur.append(strlist[i])
        getCom(depth + 1, i + 1, strlist)
        cur.pop()

getCom(0, 0, X)
getCom(0, 0, Y)
getCom(0, 0, Z)

result = []
matchl = match.items()
for k, v in matchl:
    if v >= 2: result.append(k)

if len(result) == 0: print("-1")
else:
    result.sort()
    for s in result: print(s)
