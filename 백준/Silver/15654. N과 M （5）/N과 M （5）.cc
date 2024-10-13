#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'

int N, M;
int m[8];
int a[8];
bool isUsed[8] = { false, };
void printA() {
	for (int i = 0; i < M; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}
void f(int confirmed_num) {
	if (confirmed_num == M) {
		printA();
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!isUsed[i]) {
			a[confirmed_num] = m[i];
			isUsed[i] = true;
			f(confirmed_num + 1);
			isUsed[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> m[i];
	}
	sort(m, m + N);
	f(0);
}