#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	pair<int, int> points[100000];
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		points[i] = make_pair(y, x);
	}
	sort(points, points + N);
	for (int i = 0; i < N; i++) {
		cout << points[i].second << ' ' << points[i].first << '\n';
	}
}