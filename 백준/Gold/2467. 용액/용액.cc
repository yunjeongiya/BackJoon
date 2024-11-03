#include <iostream>

using namespace std;
#define endl '\n'
#define NMAX 100000
#define ABS_MAX 1000000000
int N;
int liquids[NMAX];
int x = ABS_MAX, y = ABS_MAX;

int binary_search(int i) {
	int l, m, h;
	l = i + 1;
	h = N - 1;
	while (l + 1 < h) {
		m = (l + h) / 2;
		if (0 > (liquids[i] + liquids[m])) {
			l = m;
		}
		else if (0 < (liquids[i] + liquids[m])) {
			h = m;
		}
		else {
			return m;
		}
	}
	if (abs(liquids[i] + liquids[l]) < abs(liquids[i] + liquids[h]))
		return l;
	else return h;
}

int32_t main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> liquids[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int j = binary_search(i);
		//cout << liquids[i] << " " << liquids[j] << endl;
		if (abs(liquids[i] + liquids[j]) < abs(x + y))
		{
			x = liquids[i];
			y = liquids[j];
		}
	}
	cout << x << ' ' << y;
}