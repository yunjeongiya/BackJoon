#include <iostream>
using namespace std;
#define endl '\n';
int M, N;
int arr[8];

void printArr() {
	for (int i = 0; i < M; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void backtracking(int confirmedNum) {
	if (confirmedNum == M) {
		printArr();
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[confirmedNum] = i;
		backtracking(confirmedNum + 1);
	}
}

int32_t main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	backtracking(0);
}