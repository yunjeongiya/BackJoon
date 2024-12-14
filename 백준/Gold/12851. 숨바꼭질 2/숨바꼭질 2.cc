#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define MAX 100001 //TS 가능한 위치 범위가 100000 '이하'까지라 포함
using namespace std;
#define endl '\n'

vector<pair<int,int>> dist(MAX);
vector<set<pair<int, int>>> sets(MAX);
queue<int> Q;

void updateDist(int from, int dest, int distBetween, int op) {
	if (dest < 0 || dest >= MAX || from == dest ||
		dist[dest].first < dist[from].first + distBetween) return;
	if (dist[dest].first == dist[from].first + distBetween) {
		if (sets[dest].find(make_pair(from, op)) != sets[dest].end()) {
			return;
		}
		//cout << from << " -> " << dest << ": " << dist[from].second << endl;
		dist[dest].second += dist[from].second;
	}
	else {
		//cout << from << " -> " << dest << ": " << dist[from].second << endl;
		dist[dest].second = dist[from].second;
		sets[dest].insert(make_pair(from, op));
	}
	dist[dest].first = dist[from].first + distBetween;
	Q.push(dest);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;

	dist = vector<pair<int, int>>(MAX, make_pair(MAX, 0));
	dist[N].first = 0;
	dist[N].second = 1;
	Q.push(N);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		updateDist(cur, cur + 1, 1, 0);
		updateDist(cur, cur - 1, 1, 1);
		updateDist(cur, cur * 2, 1, 2);
	}
	cout << dist[K].first << endl << dist[K].second;
}