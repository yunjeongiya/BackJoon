#include <iostream>
#define endl '\n'
using namespace std;
int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int A, B, V;
	cin >> A >> B >> V;
	cout << 1 + (V - A) / (A - B) + ((V - A) % (A - B) ? 1 : 0);
}