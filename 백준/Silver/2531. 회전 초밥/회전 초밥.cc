#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int main(void) {
	int N, d, k, c;
	cin >> N >> d >> k >> c;
	vector<vector<bool>> masking(d + 1, vector<bool>(N, false));
	vector<int> cnt(N, 0);
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (!masking[c][i]) {
			cnt[i]++;
			if (max < cnt[i]) max = cnt[i];
		}
		masking[c][i] = true;
		int sushi;
		cin >> sushi;
		for (int j = 0; j < k; j++) {
			if (!masking[sushi][(i + j) % N]) {
				cnt[(i + j) % N]++;
				if (max < cnt[(i + j) % N]) max = cnt[(i + j) % N];
			}
			masking[sushi][(i + j) % N] = true;
		}
	}
	cout << max;
}