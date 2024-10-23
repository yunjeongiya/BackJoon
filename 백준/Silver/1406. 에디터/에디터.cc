#include <iostream>
#include <string>
#include <list>
using namespace std;
#define endl '\n'
int main(void) {
	string initial;
	cin >> initial;
	list<char> str_list;
	for (char c : initial) {
		str_list.push_back(c);
	}

	int M;
	cin >> M;
	auto iter = str_list.end();
	while (M--) {
		char command;
		cin >> command;
		switch (command) {
		case 'L':
			if (iter != str_list.begin()) iter--;
			break;
		case 'D':
			if (iter != str_list.end()) iter++;
			break;
		case 'B':
			if (iter != str_list.begin()) {
				iter--;
				iter = str_list.erase(iter);
			}
			break;
		case 'P':
			char c;
			cin >> c;
			iter = str_list.insert(iter, c);
			iter++;
		}
	}
	for (char c : str_list) {
		cout << c;
	}
}