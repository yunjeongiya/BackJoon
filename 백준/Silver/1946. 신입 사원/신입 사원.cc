#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n';

int sol() {
	int N;
	cin >> N;
	vector<pair<int, int>> ranks(N);
	for (int i = 0; i < N; i++) {
		cin >> ranks[i].first >> ranks[i].second;
	}

	//pair의 비교연산자: first 기준으로 오름차순 정렬
	sort(ranks.begin(), ranks.end()); 

	int passed = 0;
	int minSecondRank = N;
	for (auto rank : ranks) {
		if (rank.second > minSecondRank) {
			continue;
		}
		minSecondRank = rank.second;
		passed++;
	}
	return passed;
}

int32_t main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cout << sol() << endl;
	}
}