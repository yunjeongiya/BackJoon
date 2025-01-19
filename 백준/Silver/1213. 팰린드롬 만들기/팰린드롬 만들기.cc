#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define endl '\n'
#define ALPHABET_CNT 26
int main(void) {
	string name;
	cin >> name;

	//홀수개수 한개, 나머지 다 짝수면 가능
	int cnts[ALPHABET_CNT] = { 0, };
	char oddNumAlphabet = -1;
	for (int i = 0; i < name.length(); i++) {
		cnts[name[i] - 'A']++;
	}
	bool oddExists = false;
	int j = 0;
	for (int i = 0; i < ALPHABET_CNT; i++) {
		if (cnts[i] % 2 == 1) {
			if (oddExists) {
				name = "I'm Sorry Hansoo";
				break;
			}
			oddExists = true;
			name[name.length() / 2] = i + 'A';
		}
		int limit = j + cnts[i] / 2;
		for (; j < limit; j++) {
			name[j] = i + 'A';
			name[name.length() - 1 - j] = i + 'A';
		}
	}

	cout << name;
}