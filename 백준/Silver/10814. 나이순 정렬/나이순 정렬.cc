#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
	cout.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pair<int, int>> ages(n);
	vector<string> names(n);
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		ages[i] = make_pair(age, i);
		names[i] = name;
	}
	sort(ages.begin(), ages.end());
	for (int i = 0; i < n; i++) {
		cout << ages[i].first << ' ' << names[ages[i].second] << endl;
	}
}