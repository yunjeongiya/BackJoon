#include <iostream>
#include <deque>
#include <string>
using namespace std;
#define endl '\n'
#define nMAX 100000

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		string p;
		cin >> p;
		int n;
		cin >> n;
		deque<int> x;
		char garbage;
		cin >> garbage;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c >> garbage;
			// 1 <= c <= 100
			c -= '0';
			if (garbage != ',' && garbage != ']') {
				int intC;
				intC = 10 * c + garbage - '0';
				cin >> garbage;
				if (garbage != ',' && garbage != ']') {
					intC = 10 * intC + garbage - '0';
					cin >> garbage;
					x.push_back(intC);
					continue;
				}
				x.push_back(intC);
				continue;
			}
			x.push_back(c);
		}
		if (n == 0) {
			cin >> garbage;
		}

		bool isReversed = false;
		bool hasErrorOccured = false;

		// R : 전체 순서 뒤집기
		// D : 첫 번째 수 버리기
		for (char c : p) {
			if (hasErrorOccured) {
				break;
			}
			switch (c) {
			case 'R' :
				isReversed = !isReversed;
				break;
			case 'D' :
				if (x.empty()) {
					hasErrorOccured = true;
					break;
				}
				n--;
				if (isReversed) {
					x.pop_back();
					break;
				}
				x.pop_front();
				break;
			}
		}

		if (hasErrorOccured) {
			cout << "error" << endl;
			continue;
		}
		cout << '[';
		for (int i = 0; i < n; i++) {
			if (isReversed) {
				cout << x[n - i - 1];
			}
			else {
				cout << x[i];
			}
			if (i != n - 1) {
				cout << ',';
			}
		}
		cout << ']' << endl;
	}
}