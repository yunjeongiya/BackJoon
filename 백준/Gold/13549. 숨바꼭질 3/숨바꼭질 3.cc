#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100001 //TS 가능한 위치 범위가 100000 '이하'까지라 포함
using namespace std;
#define endl '\n'

vector<int> dist(MAX);
queue<int> Q;

void updateDist(int from, int dest, int distBetween) {
	if (dest < 0 || dest >= MAX || from == dest || // 0*2 = 0 이 계속 큐에 들어가서 무한루프
		//숨바꼭질1 에서는 1초 추가되니까 순간이동한게 가만있는거보다 느려서 문제되지 않았었음
		dist[dest] < dist[from] + distBetween) return;

	dist[dest] = dist[from] + distBetween;
	Q.push(dest);
}

void printRoad(int n) {
	for (int i = 0; i < n; i++) {
		cout << dist[i] << ' ';
	}
	cout << endl;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;

	dist = vector<int>(MAX, MAX);
	Q.push(N);
	dist[N] = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		updateDist(cur, cur + 1, 1);
		updateDist(cur, cur - 1, 1);
		updateDist(cur, cur * 2, 0);
	}
	//printRoad(K);
	cout << dist[K];
}