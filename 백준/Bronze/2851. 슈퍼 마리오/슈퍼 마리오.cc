#include <iostream>
using namespace std;
#define endl '\n'

int main(void) {
	int m[10];
	int closest = 0;
	for (int i = 0; i < 10; i++) {
		int thisM;
		cin >> thisM;
		if (i == 0) m[i] = thisM;
		else m[i] = m[i - 1] + thisM;
		if (abs(closest - 100) >= abs(m[i] - 100)) closest = m[i];
	}
	cout << closest;
}