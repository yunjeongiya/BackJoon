#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n';

int N, E;
vector<vector<pair<int, int>>> G;

int dijkstra(int from, int to) {
	vector<int> dist(N + 1, -1);
	dist[from] = 0;
	priority_queue<pair<int, int>> PQ;
	PQ.push({ 0, from });
	while (!PQ.empty()) {
		int curCost = PQ.top().first;
		int curVertex = PQ.top().second;
		PQ.pop();
		if (dist[curVertex] < curCost) continue;
		for (auto& e : G[curVertex]) {
			int newCost = e.second + curCost;
			if (dist[e.first] != -1 && dist[e.first] <= newCost) continue;
			dist[e.first] = newCost;
			PQ.push({ newCost, e.first });
		}
	}
	return dist[to];
}

int getDistOfPath(vector<pair<int, int>> path) {
	int sum = 0;
	for (auto& part : path) {
		int partDist = dijkstra(part.first, part.second);
		if (partDist == -1) {
			return -1;
		}
		sum += partDist;
	}
	return sum;
}

int main(void){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> E;
	G = vector<vector<pair<int, int>>>(N + 1);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({ b, c });
		G[b].push_back({ a, c });
	}
	int v1, v2;
	cin >> v1 >> v2;

	int sol1 = getDistOfPath({ {1, v1}, {v1, v2}, {v2, N} });
	int sol2 = getDistOfPath({ {1, v2}, {v2, v1}, {v1, N} });
	if (sol1 == -1 && sol2 == -1) cout << -1;
	else if (sol1 == -1 || sol2 < sol1) cout << sol2;
	else cout << sol1;
}