#include <iostream>
#include <vector>
using namespace std;
#define ull unsigned long long
#define endl '\n'

bool verifyAnt(int X, int Y, int N, vector<ull> &culSum) {
	ull head = culSum[X];
	ull chest = culSum[Y] - culSum[X];
	ull belly = culSum[N] - culSum[Y];
	//cout << head << ", " << chest << ", " << belly << endl;
	return chest > belly && belly > head;
}

void printAnt(int X, int Y, int N, vector<ull> &culSum) {
	for (int i = 1; i <= N; i++) {
		char divider = ' ';
		if (i == X || i == Y) {
			divider = '|';
		}
		cout << culSum[i] << divider;
	}
	cout << endl;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<ull> culSum(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> culSum[i];
		culSum[i] += culSum[i - 1];
	}
	ull cnt = 0;
	for (int Y = 2; Y < N; Y++) {
		if (!verifyAnt(1, Y, N, culSum)) {
			continue;
		}
		if (verifyAnt(Y - 1, Y, N, culSum)) {
			cnt += Y - 1;
			continue;
		}
		int l = 1, h = Y - 1;
		while (l + 1 < h) {
			int m = (l + h) / 2;
			if (verifyAnt(m, Y, N, culSum)) {
				l = m;
			}
			else {
				h = m;
			}
		}
		cnt += l;
	}
	cout << cnt;
}