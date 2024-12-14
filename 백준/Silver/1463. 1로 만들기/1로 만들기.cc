#include <iostream>
using namespace std;
#define endl '\n'
#define MAX 1000001

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	int dist[MAX] = { 0, };
	for (int i = 2; i <= N; i++) {
		dist[i] = dist[i - 1] + 1;
		if (i % 2 == 0) dist[i] = min(dist[i], dist[i / 2] + 1);
		if (i % 3 == 0) dist[i] = min(dist[i], dist[i / 3] + 1);
	}
	cout << dist[N];
}