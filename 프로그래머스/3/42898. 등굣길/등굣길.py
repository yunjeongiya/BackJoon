def solution(m, n, puddles):
    t = [[0 for _ in range(m)] for _ in range(n)]
    t[0][0] = 1
    puddles = set(map(tuple, puddles))
    for i in range(n):
        for j in range(m):
            if (j+1, i+1) in puddles: #잠긴 지역 10개 이하니까 그냥 비효율적이어도 냅둠...
                continue
            if i > 0:
                t[i][j] += t[i-1][j]
            if j > 0:
                t[i][j] += t[i][j-1]
            t[i][j] %= 1000000007
    return t[n-1][m-1]