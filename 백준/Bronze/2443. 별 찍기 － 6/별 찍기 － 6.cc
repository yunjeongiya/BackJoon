#include <iostream>
using namespace std;
#define endl '\n';

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = N; i >= 1; i--) {
		for (int j = 0; j < N - i; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
}