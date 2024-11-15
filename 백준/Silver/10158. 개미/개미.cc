#include <iostream>
#define endl '\n'
using namespace std;

int func(int t, int w, int p) {
	int timeTilFirstBump = w - p;
	if (t <= timeTilFirstBump) {
		return p + t;
	}
	t -= timeTilFirstBump;
	if ((t / w) % 2) {
		return t % w;
	}
	return w - t % w;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int w, h;
	cin >> w >> h;
	int p, q;
	cin >> p >> q;
	int t;
	cin >> t;

	cout << func(t, w, p) << ' ' << func(t, h, q);
}