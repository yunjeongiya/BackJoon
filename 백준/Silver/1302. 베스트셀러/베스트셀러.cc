#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#define endl '\n'
int32_t main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	unordered_map<string, int> map;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (map.find(s) == map.end()) {
			map[s] = 0;
		}
		map[s] += 1;
	}
	int max = 0;
	vector<string> maxItems;
	for (auto p : map) {
		if (p.second < max) {
			continue;
		}
		if (p.second > max) {
			maxItems = vector<string>();
			max = p.second;
		}
		maxItems.push_back(p.first);
	}
	string minABCItem = maxItems[0];
	for (auto item : maxItems) {
		minABCItem = min(minABCItem, item);
	}
	cout << minABCItem;
}