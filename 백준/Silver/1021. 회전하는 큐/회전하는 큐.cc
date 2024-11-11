#include <iostream>
#include <deque>
#define endl '\n'
using namespace std;
void printDeque(deque<int>& dq) {
	cout << endl;
	for (int n : dq) {
		cout << n << ' ';
	}
	cout << endl;
}
bool isTargetCloseToLeft(int target, deque<int>& dq) {
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] != target) {
			continue;
		}
		return i <= dq.size() / 2;
	}
}
void rotateLeft(deque<int>& dq) {
	dq.push_back(dq.front());
	dq.pop_front();
}
void rotateRight(deque<int>& dq) {
	dq.push_front(dq.back());
	dq.pop_back();
}
int main(void) {
	int N, M;
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	int cnt = 0;
	while (M--) {
		int target;
		cin >> target;
		//printDeque(dq);
		while (dq.front() != target) {
			if (isTargetCloseToLeft(target, dq)) {
				rotateLeft(dq);
				//cout << "왼쪽 회전" << endl;
			}
			else {
				rotateRight(dq);
				//cout << "오른쪽 회전" << endl;
			}
			//printDeque(dq);
			cnt++;
		}
		dq.pop_front();
		//cout << "왼쪽 pop" << endl;
	}
	cout << cnt;
}