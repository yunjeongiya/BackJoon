#include <iostream>
using namespace std;
#define endl '\n'
#define MAX 1000001

int dist[MAX] = { -1, 0, };
int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		dist[i] = dist[i - 1] + 1;
		if (i % 2 == 0 && dist[i] > dist[i / 2] + 1) { dist[i] = dist[i / 2] + 1; }
		if (i % 3 == 0 && dist[i] > dist[i / 3] + 1) { dist[i] = dist[i / 3] + 1; }
	}
	cout << dist[N] << endl;
	int i = N;
	while (i != 0) {
		cout << i << ' ';
		if (dist[i] == dist[i - 1] + 1) i = i - 1;
		else if (i % 2 == 0 && dist[i] == dist[i / 2] + 1) { i = i / 2; }
		else if (i % 3 == 0 && dist[i] == dist[i / 3] + 1) { i = i / 3; }
	}
}