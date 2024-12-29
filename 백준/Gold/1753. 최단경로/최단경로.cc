#include <iostream>
#include <vector>
#include <queue>
#include <climits> // for INT_MAX
using namespace std;
#define endl '\n';

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int V, E;
    cin >> V >> E;
    vector<int> dist(V + 1, INT_MAX); // INF로 초기화
    vector<vector<pair<int, int>>> G(V + 1);

    int start;
    cin >> start;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({ v, w });
    }

    // 우선순위 큐 {비용, 정점}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({ 0, start }); // 시작점 추가

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        // 이미 처리된 거리보다 크면 무시
        if (curDist > dist[cur]) continue;

        for (auto& edge : G[cur]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[cur] + weight < dist[next]) {
                dist[next] = dist[cur] + weight;
                pq.push({ dist[next], next });
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
