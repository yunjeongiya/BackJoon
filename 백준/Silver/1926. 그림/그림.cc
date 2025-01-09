#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#define endl '\n'

void print(vector<vector<int>>& paper) {
	cout << "----------------------" << endl;
	for (int i = 0; i < paper.size(); i++) {
		for (int j = 0; j < paper[i].size(); j++) {
			cout << paper[i][j];
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	int cnt = 0, maxArea = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 0) continue;
			cnt++;
			int area = 0;
			queue<pair<int, int>> q;
			q.push({ i, j });
            paper[i][j] = 0;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				area++;
				//print(paper);
				//cout << x << ", " << y << ": " << area << endl;
				int dx[] = { 0, 0, 1, -1 };
				int dy[] = { 1, -1, 0, 0 };
				for (int k = 0; k < 4; k++) {
					int newX = x + dx[k];
					int newY = y + dy[k];
					if (newX < 0 || n <= newX || newY < 0 || m <= newY) continue;
					if (paper[newX][newY] == 0) continue;
					paper[newX][newY] = 0;
					q.push({ newX, newY });
				}
			}
			if (area > maxArea) maxArea = area;
		}
	}
	cout << cnt << endl << maxArea;
}