#include <iostream>
using namespace std;

int main(void) {
	bool arr[42] = { 0, };
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		int mod = n % 42;
		if (!arr[mod])cnt++;
		arr[mod] = true;
	}
	cout << cnt;
}
