#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int A[1000000];
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i] = -a;
	}
	sort(A, A + N);
	for (int i = 0; i < N; i++) {
		cout << -A[i] << '\n';
	}
}