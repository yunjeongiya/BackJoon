#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n';

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = N; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}