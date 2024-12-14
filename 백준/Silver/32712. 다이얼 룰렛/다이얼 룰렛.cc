#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200001
#define endl '\n'

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, K;
	long long ASum[MAX] = { 0, };
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int A;
		cin >> A;
		ASum[i] = ASum[i - 1] + A;
	}
	long long maxPoint = 0;
	for (int i = 1; i <= N; i++) {
		long long turnRight = 0, turnLeft = 0;
		int A = ASum[i] - ASum[i - 1];
		
		if (K - i >= 0) {
			turnLeft = ASum[i] + (long long)(K - i) * A;
		}
		if (K - (N - i + 1) >= 0) {
			turnRight = (ASum[N] - ASum[i == 1 ? N : i - 1]) + (long long)(K - (N - i + 1)) * A;
		}
		maxPoint = max({ maxPoint, turnRight, turnLeft });
	}
	cout << maxPoint;
}