#include <iostream>
#include <string>
using namespace std;
int main(void){
	string s;
	cin >> s;
	int sum = 0;
	int vals[26] = {
		2, 2, 2,
		3, 3, 3,
		4, 4, 4,
		5, 5, 5,
		6, 6, 6,
		7, 7, 7, 7,
		8, 8, 8,
		9, 9, 9, 9
	};
	for (char c : s) {
		sum += vals[c - 'A'] + 1;
	}
	cout << sum;
}