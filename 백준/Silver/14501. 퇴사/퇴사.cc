#include <iostream>
using namespace std;
#define endl '\n';
#define MAX 16

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	int T[MAX], P[MAX];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	int earned[MAX] = { 0, };
	for(int i = 0; i < N; i++) {
		if (i + T[i] <= N && earned[i + T[i]] < earned[i] + P[i])
			earned[i + T[i]] = earned[i] + P[i];
		if (i + 1 <= N && earned[i + 1] < earned[i])
			earned[i + 1] = earned[i];
	}

	cout << earned[N];
}