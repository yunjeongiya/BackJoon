#include <iostream>
#include <deque>
#define endl '\n'
using namespace std;
int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		deque<pair<int, bool>> Q; //중요도 저장
		for (int i = 0; i < N; i++) {
			int d;
			cin >> d;
			Q.push_back(make_pair(d, (i == M)));
		}
		int cnt = 0;
		while (!Q.empty()) {
			bool flag = false;
			for (pair<int, bool> d : Q) {
				if (d.first > Q[0].first) {
					Q.push_back(Q[0]);
					Q.pop_front();
					flag = true;
					break;
				}
			}
			if (flag) continue;
			if (Q[0].second) break;
			Q.pop_front();
			cnt++;
		}
		cout << cnt + 1 << endl;
	}
}