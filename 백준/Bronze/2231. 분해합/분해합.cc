#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	cout.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	int i = 1;
	while (i++ < 1000000) {
		int sum = i;
		int j = i;
		while (j) {
			sum += j % 10;
			j /= 10;
		}
		if (sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}