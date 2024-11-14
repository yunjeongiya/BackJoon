import sys
input = sys.stdin.readline

n,m = map(int,input().split())
r,c,d = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(n)]

#0 1 2 3 - 북 동 남 서
dlist = [(-1,0),(0,1),(1,0),(0,-1)]
result = 1
board[r][c] = -1
while True:
    isBack = True
    for _ in range(4):
        d = (d+3) % 4
        nx = r + dlist[d][0]
        ny = c + dlist[d][1] 

        if nx >= n or nx < 0 or ny >= m or ny < 0:
            continue
        if board[nx][ny] != 0:
            continue
        board[nx][ny] = -1
        r = nx
        c = ny
        result += 1
        isBack = False
        break
    if isBack:
        nx = r - dlist[d][0]
        ny = c - dlist[d][1]
        if board[nx][ny] == 1:
            break
        r = nx
        c = ny
print(result)