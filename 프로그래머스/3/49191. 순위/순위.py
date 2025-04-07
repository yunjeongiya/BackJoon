def dfs(i, graph, visited):
    visited[i] = True
    for connected in list(graph[i]):  # 복사본 순회
        if not visited[connected]:
            dfs(connected, graph, visited)
        graph[i] |= graph[connected]  # 관계 확장

def solution(n, results):
    highers = [set() for _ in range(n+1)]
    lowers = [set() for _ in range(n+1)]
    
    # 초기 경기 결과 입력
    for a, b in results:
        highers[b].add(a)  # b를 이긴 선수 목록
        lowers[a].add(b)   # a에게 진 선수 목록
    
    # 정방향 DFS: 간접적 승자 관계 확장
    for i in range(1, n+1):
        visited = [False]*(n+1)
        dfs(i, highers, visited)
    
    # 역방향 DFS: 간접적 패자 관계 확장
    for i in range(1, n+1):
        visited = [False]*(n+1)
        dfs(i, lowers, visited)
    
    # 정확한 순위 판별
    return sum(1 for i in range(1, n+1) 
              if len(highers[i]) + len(lowers[i]) == n-1)
