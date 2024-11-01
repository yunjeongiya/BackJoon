#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
int N, M;
int nums[8];
int arr[9];
void func(int fixedCnt) {
	if (fixedCnt == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (fixedCnt > 0 && arr[fixedCnt] > nums[i]) {
			continue;
		}
		arr[fixedCnt + 1] = nums[i];
		func(fixedCnt + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + N);
	func(0);
}