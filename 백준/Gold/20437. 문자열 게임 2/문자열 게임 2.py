import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    word = list(input().strip())
    K = int(input())
    ansMax = -1
    ansMin = 100000
    check = [[] for _ in range(26)]
    
    length = len(word)
    for i in range(length):
        check[ord(word[i]) - 97].append(i)
    
    for w in check:
        wlen = len(w)
        for i in range(wlen - K + 1):
            ansMax = max(ansMax, w[i + K - 1] - w[i] + 1)
            ansMin = min(ansMin, w[i + K - 1] - w[i] + 1)
    
    if ansMax == -1: print(-1)
    else: print(ansMin, ansMax)