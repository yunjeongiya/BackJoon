#include <iostream>
using namespace std;
#include <string>
#define endl '\n'

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, newS = "";
	cin >> s;
	for (char c : s) {
		if (newS + c <= c + newS) {
			newS = newS + c;
		}
		else {
			newS = c + newS;
		}
	}
	cout << newS;
} 