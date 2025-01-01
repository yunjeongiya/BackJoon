#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n';

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m, r;
	cin >> n >> m >> r;
	vector<int> t(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	vector<vector<pair<int, int>>> roads(n + 1);
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		roads[a].push_back({ b, l });
		roads[b].push_back({ a, l });
	}

	int max = 0;
	for (int start = 1; start <= n; start++) {
		vector<int> dists(n + 1, -1);
		dists[start] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> PQ;
		PQ.push({ 0, start });
		while (!PQ.empty()) {
			int curDist = PQ.top().first;
			int curArea = PQ.top().second;
			PQ.pop();
			if (dists[curArea] < curDist) continue;
			for (auto& road : roads[curArea]) {
				int nextArea = road.first;
				int nextNewDist = road.second + curDist;
				if (dists[nextArea] != -1 && dists[nextArea] <= nextNewDist) continue;
				dists[nextArea] = nextNewDist;
				PQ.push({ nextNewDist, nextArea });
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (dists[i] > m || dists[i] == -1) continue;
			sum += t[i];
		}
		//cout << start << ": " << sum << endl;
		if (max < sum) max = sum;
	}
	cout << max;
}