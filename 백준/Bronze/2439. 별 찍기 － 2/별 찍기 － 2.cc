#include <iostream>
using namespace std;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = N; i > 0; i--) {
		for (int j = 1; j <= N; j++) {
			if (j < i) {
				cout << ' ';
			}
			else {
				cout << '*';
			}
		}
		cout << endl;
	}
}