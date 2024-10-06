#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define endl '\n';
int M, N;
int arr[8];

template <typename T>
void printArr(T arr) {
	for (int i = 0; i < M; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void backtracking(int confirmedNum) {
	if (confirmedNum == M) {
		printArr<int*>(arr);
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[confirmedNum] = i;
		backtracking(confirmedNum + 1);
	}
}

void backtrackingWithStack() {
	stack<vector<int>> s;
	s.push(vector<int> {});
	while (!s.empty()) {
		vector<int> v = s.top();
		s.pop();
		if (v.size() == M) {
			printArr<vector<int>>(v);
			continue;
		}
		for (int i = N; i >= 1; i--) {
			v.push_back(i);
			s.push(vector<int>(v));
			v.pop_back();
		}
	}
}

int32_t main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	backtracking(0);
	//backtrackingWithStack();
}