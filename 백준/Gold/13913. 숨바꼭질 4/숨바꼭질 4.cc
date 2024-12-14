#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#define MAX 100001 //TS 가능한 위치 범위가 100000 '이하'까지라 포함
using namespace std;
#define endl '\n'

vector<pair<int, int>> dist(MAX);
queue<int> Q;

void updateDist(int from, int dest, int distBetween) {
	if (dest < 0 || dest >= MAX || from == dest ||
		dist[dest].first < dist[from].first + distBetween) return;
	dist[dest].first = dist[from].first + distBetween;
	dist[dest].second = from;
	Q.push(dest);
}

void printRoad(int K) {
	for (int i = 0; i <= K; i++) {
		cout << dist[i].second << ' ';
	}
	cout << endl;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;

	dist = vector<pair<int, int>>(MAX, make_pair(MAX, -1));
	Q.push(N);
	dist[N].first = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		updateDist(cur, cur + 1, 1);
		updateDist(cur, cur - 1, 1);
		updateDist(cur, cur * 2, 1);
	}
	//printRoad(K);
	cout << dist[K].first << endl;
	stack<int> route;
	do {
		route.push(K);
		K = dist[K].second;
	} while (route.top() != N);
	while (!route.empty()) {
		cout << route.top() << ' ';
		route.pop();
	}
}