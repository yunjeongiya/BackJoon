#include <iostream>
#define endl '\n'
#include <deque>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	bool flag = false;
	while (dq.size() > 1) {
		if(flag) dq.push_back(dq.front());
		dq.pop_front();
		flag = !flag;
	}
	cout << dq.front();
}