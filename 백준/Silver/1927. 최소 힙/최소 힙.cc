#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	priority_queue<unsigned int,
		vector<unsigned int>,
		greater<unsigned int>> pq;
	while(N--) {
		unsigned int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << endl;
				continue;
			}
			cout << pq.top() << endl;
			pq.pop();
			continue;
		}
		pq.push(x);
	}
}