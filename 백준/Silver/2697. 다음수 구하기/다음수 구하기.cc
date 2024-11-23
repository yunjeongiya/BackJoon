#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		string A;
		cin >> A;
		if(A.length() < 2) {
			cout << "BIGGEST" << endl;
			continue;
		}
		int i = A.length() - 2;
		for (; i >= 0; i--) {
			if (A[i + 1] > A[i]) {
				break;
			}
		}
		if (i == -1) {
			cout << "BIGGEST" << endl;
			continue;
		}
		int j = A.length() - 1;
		for (; j >= 0; j--) {
			if (A[i] < A[j]) {
				break;
			}
		}
		char tmp = A[j];
		A[j] = A[i];
		A[i] = tmp;
		sort(A.begin() + i + 1, A.end());
		cout << A << endl;
	}
}