#include <iostream>
using namespace std;
#define endl '\n'

long long P[51] = { 1, }, B[51] = { 0, }, L[51] = { 1, };

long long f(int N, long long X) {
	if (X == 1) {
		if (N == 0) return 1;
		else return 0;
	}
	if (X <= 1 + L[N - 1]) {
		return f(N - 1, X - 1);
	}
	if (X == 2 + L[N - 1]) {
		return P[N - 1] + 1;
	}
	if (X <= 2 + 2 * L[N - 1]) {
		return P[N - 1] + 1 + f(N - 1, X - (L[N - 1] + 2));
	}
	return P[N - 1] * 2 + 1;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	long long X;
	cin >> N >> X;
	for (int i = 1; i <= 50; i++) {
		P[i] = P[i - 1] * 2 + 1;
		B[i] = B[i - 1] * 2 + 2;
		L[i] = P[i] + B[i];
		//cout << L[i] << endl; //overflow check
	}
	cout << f(N, X);
}