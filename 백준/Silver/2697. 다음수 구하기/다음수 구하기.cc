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
		if (!next_permutation(A.begin(), A.end())) A = "BIGGEST";
		cout << A << endl;
	}
}