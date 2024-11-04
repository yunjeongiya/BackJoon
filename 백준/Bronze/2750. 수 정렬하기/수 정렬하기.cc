#include <iostream>
using namespace std;
#include <algorithm>
#define endl '\n'
int N;
int arr[1000];
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}
} 