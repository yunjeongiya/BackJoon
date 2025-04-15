from collections import deque

dx, dy = (0, 0, 1, -1), (1, -1, 0, 0)
def solution(maps):
    #가중치 없는 그래프 -> BFS
    n, m = len(maps), len(maps[0])
    q = deque()
    q.append((0, 0))
    while len(q) != 0:
        x, y = q.popleft()
        for i in range(4):
            nextX, nextY = x + dx[i], y + dy[i]
            if 0 <= nextX < n and 0 <= nextY < m and maps[nextX][nextY] == 1:                
                maps[nextX][nextY] += maps[x][y]
                if nextX == n-1 and nextY == m-1:
                    return maps[nextX][nextY]
                q.append((nextX, nextY))
            
    return -1