#include <iostream>
using namespace std;
#define endl '\n';

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j >= i) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
}