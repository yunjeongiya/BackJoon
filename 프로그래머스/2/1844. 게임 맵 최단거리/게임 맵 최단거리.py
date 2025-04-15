from collections import deque

def solution(maps):
    # 맵 크기: n은 행(row)의 개수, m은 열(column)의 개수
    n, m = len(maps), len(maps[0])
    
    # 이동 방향 (상, 하, 좌, 우)
    # dx: 행 방향, dy: 열 방향
    dx = [-1, 1, 0, 0]  # 위로(-1), 아래로(+1), 그대로(0), 그대로(0)
    dy = [0, 0, -1, 1]  # 그대로(0), 그대로(0), 왼쪽(-1), 오른쪽(+1)
    
    # BFS 함수
    def bfs(x, y):
        queue = deque([(x, y)])  # 시작 좌표를 큐에 추가
        
        while queue:
            x, y = queue.popleft()  # 현재 좌표
            
            # 현재 위치에서 4방향 탐색
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]  # 새로운 좌표 (행: nx, 열: ny)
                
                # 맵 범위 안에 있고, 벽이 아니며 아직 방문하지 않은 경우
                if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1:
                    # 이동 거리 기록 (이전 거리 + 1)
                    maps[nx][ny] = maps[x][y] + 1
                    queue.append((nx, ny))
        
        # 상대 팀 진영 (행: n-1, 열: m-1)의 값이 초기 값(1)에서 변경되지 않았다면 도달 불가
        return maps[n-1][m-1] if maps[n-1][m-1] > 1 else -1

    # BFS 탐색 시작
    return bfs(0, 0)  # 좌측 상단 (행: 0, 열: 0)에서 시작