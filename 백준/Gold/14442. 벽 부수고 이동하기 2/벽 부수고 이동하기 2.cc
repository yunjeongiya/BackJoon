#include<iostream>
#include<queue>
using namespace std;

int n, m, k, a[1004][1004], visited[1004][1004], macnt[1004][1004];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
char c;
struct A {
	int y;
	int x;
	int cnt;
};
queue<A> q;

void go() {
	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		if (macnt[y][x] < cnt) continue;
		if (y == n-1 && x == m-1) return;
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] && macnt[ny][nx] <= cnt) continue; // 더 적게 부수고 갈 수 있을 때
			if (cnt < k && a[ny][nx]) { //부술 기회 남았고 벽일 때
					visited[ny][nx] = visited[y][x] + 1;
					macnt[ny][nx] = cnt + 1;
					q.push({ ny,nx, cnt + 1 });
			}
			if (a[ny][nx]) continue; // 부술 기회 없는데 벽일 때
			visited[ny][nx] = visited[y][x] + 1; 
			macnt[ny][nx] = cnt;
			q.push({ ny,nx, cnt });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	visited[0][0] = 1;
	q.push({ 0,0,0 });
	go();
	if (visited[n - 1][m - 1]) cout << visited[n - 1][m - 1];
	else cout << -1;
}