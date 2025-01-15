#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int A[8], orders[8];
	int cnt = 0;
	int N, K;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		orders[i] = i;
	}

	do {
		//cout << endl;
		int weight = 500;
		int i = 0;
		for (; i < N; i++) {
			//cout << orders[i] << " ";
			int newWeight = weight - K + A[orders[i]];
			if (newWeight < 500) break;
			weight = newWeight;
		}
		if (i == N) cnt++;
	} while (next_permutation(orders, orders + N));

	cout << cnt;
}
