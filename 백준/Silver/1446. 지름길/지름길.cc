#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define MAX 10000

int dist[MAX + 1];
bool confirmed[MAX + 1] = { 0, };
int main(void) {
	int N, D;
	cin >> N >> D;
	int cnt = N;
	vector<vector<pair<int, int>>> roadsFrom(MAX + 1);

	while (cnt--) {
		int start, end, dist;
		cin >> start >> end >> dist;
		roadsFrom[start].push_back({ end, dist });
	}

	for (int i = 0; i <= MAX; i++) {
		dist[i] = MAX;
		if (i == 0) dist[i] = 0;
		if (i != MAX) roadsFrom[i].push_back({ i + 1, 1 });
	}

	cnt = MAX;
	while (cnt--) {
		int curMin = -1;
		int curMinDist = MAX;
		for (int i = 0; i <= MAX; i++) {
			if (!confirmed[i] && curMinDist > dist[i]) {
				curMinDist = dist[i];
				curMin = i;
			}
		}
		if (curMin == -1) break;
		confirmed[curMin] = true;

		for (auto& roads : roadsFrom[curMin]) {
			if (confirmed[roads.first]) continue;
			if (dist[roads.first] < curMinDist + roads.second) continue;
			dist[roads.first] = curMinDist + roads.second;
		}
	}

	cout << dist[D];
}