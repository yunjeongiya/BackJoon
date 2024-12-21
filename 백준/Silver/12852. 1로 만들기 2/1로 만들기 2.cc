#include <iostream>
using namespace std;
#define endl '\n'
#define MAX 1000001

int dist[MAX] = { 0, 0, };
int pre[MAX] = { -1, -1, };
int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		dist[i] = dist[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0 && dist[i] > dist[i / 2] + 1) { dist[i] = dist[i / 2] + 1; pre[i] = i / 2; }
		if (i % 3 == 0 && dist[i] > dist[i / 3] + 1) { dist[i] = dist[i / 3] + 1; pre[i] = i / 3; }
	}
	cout << dist[N] << endl;
	while (N != -1) {
		cout << N << ' ';
		N = pre[N];
	}
}