#include <iostream>
#include <list>
#include <string>
using namespace std;
#define endl '\n'
int main(void) {
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		list<char> list_str;
		for (char c : str) {
			if (c == ')' && !list_str.empty() && list_str.back() == '(') {
				list_str.pop_back();
				continue;
			}
			list_str.push_back(c);
		}
		if (list_str.empty()) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
}