#include <iostream>
#include <string>
#include <deque>
#define endl '\n'
using namespace std;
bool onTest = false;
template <typename T>
void testPrintSingle(const T& arg) {
	cout << arg;
}

template <typename T, typename... Args>
void testPrint(const T& first, const Args&... args) {
	if (!onTest) return;
	testPrintSingle(first);
	int dummy[] = { 0, (testPrintSingle(args), 0)... };
	(void)dummy; // 컴파일 경고 억제
}

void sol()
{
	string str, bomb;
	cin >> str >> bomb;
	string ans = "";
	deque<string> dq;
	for (int str_p = 0, bomb_p = 0;
		str_p < str.length(); str_p++) {
		if (str[str_p] == bomb[0]) {
			if (bomb.length() == 1) {
				continue;
			}
			dq.push_back(string{ bomb[0] });
			bomb_p = 1;
			continue;
		}
		if (str[str_p] == bomb[bomb_p]) {
			string tmp = dq.back();
			dq.pop_back();
			dq.push_back(tmp + str[str_p]);
			bomb_p++;
			if (bomb_p == bomb.length()) {
				testPrint("explode!", endl);
				dq.pop_back();
				if (dq.empty()) {
					bomb_p = 0;
				}
				else {
					bomb_p = dq.back().length();
				}
			}
			continue;
		}
		while (!dq.empty()) {
			ans += dq.front();
			dq.pop_front();
			bomb_p = 0;
		}
		ans += str[str_p];
		testPrint(ans, endl);
	}
	while (!dq.empty()) {
		ans += dq.front();
		dq.pop_front();
	}
	if (ans.empty()) ans = "FRULA";
	cout << ans;
}

int main() {
	cout.tie(0);
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (true) {
		sol();
		if (!onTest) {
			break;
		}
	}
}