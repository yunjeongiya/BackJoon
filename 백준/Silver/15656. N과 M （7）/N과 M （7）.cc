#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int N, M, A[8], B[8];

void func(int i) {
	if (i == M) {
		for (int i = 1; i <= M; i++) {
			cout << B[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int j = 1; j <= N; j++) {
		B[i + 1] = A[j];
		func(i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	func(0);
}