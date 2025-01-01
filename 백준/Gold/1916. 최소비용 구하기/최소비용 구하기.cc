#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n';
int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> busesFrom(N + 1);
	vector<int> dist(N + 1, -1); //max: N * maxCost = 10^8
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		busesFrom[from].push_back({ cost, to });
	}
	int from, to;
	cin >> from >> to;
	dist[from] = 0;
	queue<pair<int, int>> PQ;
	PQ.push({ 0, from });
	while (!PQ.empty()) {
		int curDist = PQ.front().first;
		int curTo = PQ.front().second;
		PQ.pop();
		if (curDist > dist[curTo]) continue;
		for (auto& bus : busesFrom[curTo]) {
			int newDist = curDist + bus.first;
			if (dist[bus.second] != -1 && dist[bus.second] <= newDist) {
				continue;
			}
			dist[bus.second] = newDist;
			PQ.push({ newDist, bus.second });
		}
	}

	cout << dist[to];
}