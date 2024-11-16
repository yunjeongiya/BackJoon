#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
#define MAX 100000
int main() {
	int n;
	pair<int, int> AH[MAX];

	cin >> n;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		AH[i] = make_pair(0, h);
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		AH[i].first = a;
	}
	sort(AH, AH + n);

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += AH[i].second + AH[i].first * i;
	}
	cout << sum;
}