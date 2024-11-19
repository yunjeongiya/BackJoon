#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;
#define MAX 100000

int main() {
	cout.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	pair<int, int> list[MAX];
	string names[MAX];
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		list[i] = make_pair(age, i);
		names[i] = name;
	}
	sort(list, list + n);
	for (int i = 0; i < n; i++) {
		cout << list[i].first << ' ' << names[list[i].second] << endl;
	}
}