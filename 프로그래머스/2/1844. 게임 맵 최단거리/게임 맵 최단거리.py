from collections import deque

dx = (0, 0, 1, -1)
dy = (1, -1, 0, 0)
def solution(maps):
    #가중치 없는 그래프 -> BFS
    n = len(maps)
    m = len(maps[0])
    q = deque()
    q.append((0, 0))
    while len(q) != 0:
        x, y = q.popleft()
        for i in range(4):
            nextX = x + dx[i]   
            nextY = y + dy[i]
            
            if (nextX == 0 and nextY == 0) or (nextX < 0 or nextX >= n or nextY < 0 or nextY >= m):
                continue
            if (maps[nextX][nextY] != 1):
                continue
                
            maps[nextX][nextY] += maps[x][y]
            if nextX == n-1 and nextY == m-1:
                return maps[nextX][nextY]
            q.append((nextX, nextY))
            
    return -1