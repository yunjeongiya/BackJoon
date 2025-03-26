from collections import deque

def solution(n, edge):
    graph = [[] for _ in range(n + 1)]
    for x, y in edge:
        graph[x].append(y)
        graph[y].append(x)

    dists = [-1] * (n + 1)
    dists[1] = 0  # 시작 노드 거리 0
    que = deque([1])  # BFS 큐

    while que:
        cur = que.popleft()
        for v in graph[cur]:
            if dists[v] == -1:  # 첫 방문이면 최단거리 확정
                dists[v] = dists[cur] + 1
                que.append(v)

    return dists.count(max(dists))
