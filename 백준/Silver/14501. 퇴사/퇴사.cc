#include <iostream>
using namespace std;
#define endl '\n';
#define MAX 15
#include <stack>


int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	int T[MAX], P[MAX];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	int ans = 0;
	stack<pair<int, int>> s; //오늘 날짜, 여태까지 수익
	s.push({ 0, 0 });
	while (!s.empty()) {
		int i = s.top().first;
		int sum = s.top().second;
		s.pop();
		if (i == N && ans < sum) ans = sum;
		if (i >= N) continue;
		s.push({ i + T[i], sum + P[i] });
		s.push({ i + 1, sum });
	}

	cout << ans;
}