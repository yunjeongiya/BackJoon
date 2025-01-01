#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define endl '\n';

void dijkstra(int from, vector<int>& dist, vector<vector<pair<int, int>>>& G) {
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
}

int getDistOfPath(vector<pair<int, int>> path, map<int, vector<int>>& distVecMap) {
	int sum = 0;
	for (auto& part : path) {
		int partDist = distVecMap[part.first][part.second];
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

	int N, E;
	vector<vector<pair<int, int>>> G;
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
	map<int, vector<int>> distVecMap({
		{1, vector<int>(N + 1, -1)},
		{v1, vector<int>(N + 1, -1)},
		{v2, vector<int>(N + 1, -1)},
		});

	dijkstra(1, distVecMap[1], G);
	dijkstra(v1, distVecMap[v1], G);
	dijkstra(v2, distVecMap[v2], G);

	int sol1 = getDistOfPath({ {1, v1}, {v1, v2}, {v2, N} }, distVecMap);
	int sol2 = getDistOfPath({ {1, v2}, {v2, v1}, {v1, N} }, distVecMap);
	if (sol1 == -1 && sol2 == -1) cout << -1;
	else if (sol1 == -1 || sol2 < sol1) cout << sol2;
	else cout << sol1;
}