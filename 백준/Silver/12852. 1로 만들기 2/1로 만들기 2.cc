#include <iostream>
using namespace std;
#define endl '\n'
#define MAX 1000001

pair<int, int> dist[MAX] = { {-1, 0}, {-1, 0}, };
int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		dist[i] = { i - 1, dist[i - 1].second + 1 };
		if (i % 2 == 0 && dist[i].second > dist[i / 2].second + 1) dist[i] = { i / 2, dist[i / 2].second + 1 };
		if (i % 3 == 0 && dist[i].second > dist[i / 3].second + 1) dist[i] = { i / 3, dist[i / 3].second + 1 };
	}
	cout << dist[N].second << endl;
	while (N != -1) {
		cout << N << ' ';
		N = dist[N].first;
	}
}