def solution(n, results):
    # 플로이드-워셜을 위한 그래프 초기화
    graph = [[False]*(n+1) for _ in range(n+1)]
    for a, b in results:
        graph[a][b] = True
    
    # 전이적 폐쇄 계산
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if graph[i][k] and graph[k][j]:
                    graph[i][j] = True
    
    # 승패 집합 크기 확인
    answer = 0
    for i in range(1, n+1):
        wins = sum(graph[i][1:])
        losses = sum(graph[j][i] for j in range(1, n+1))
        if wins + losses == n-1:
            answer += 1
    return answer
