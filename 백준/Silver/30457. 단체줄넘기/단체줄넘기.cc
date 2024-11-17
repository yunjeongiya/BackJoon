#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int main() {
	int N, A[1001] = { 0, };
	cin >> N;
	while(N--) {
		int a;
		cin >> a;
		A[a]++;
	}
	int cnt = 0;
	for (int i = 1; i <= 1000; i++) {
		if (1 == A[i]) cnt += 1;
		if (2 <= A[i]) cnt += 2;
	}
	cout << cnt;
}