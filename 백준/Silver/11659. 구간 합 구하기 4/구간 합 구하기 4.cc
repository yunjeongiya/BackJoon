#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<int> culSum(N + 1, 0);
	for (int k = 1; k <= N; k++) {
		cin >> culSum[k];
		culSum[k] += culSum[k - 1];
	}
	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		cout << culSum[j] - culSum[--i] << endl;
	}
}