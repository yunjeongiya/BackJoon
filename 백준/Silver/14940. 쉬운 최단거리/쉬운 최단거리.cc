#include <iostream>
using namespace std;
#define endl '\n'
#define MAX 1000
#include <queue>
#include <algorithm>
int map[MAX][MAX];
int dist[MAX][MAX];

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = 0;

			cin >> map[i][j];
			if (map[i][j] == 1) {
				dist[i][j] = -1;
			}
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
		}
	}
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	queue<pair<int, int>> Q;
	Q.push({ x, y });
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX < 0 || newX >= n ||
				newY < 0 || newY >= m ||
				map[newX][newY] == 0 ||
				dist[newX][newY] != -1 &&
				dist[newX][newY] <= dist[x][y] + 1) {
				continue;
			}
			dist[newX][newY] = dist[x][y] + 1;
			Q.push({ newX, newY });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}