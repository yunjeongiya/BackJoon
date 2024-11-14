#include <iostream>
#include <sstream>
#define endl '\n'
using namespace std;

bool isTesting = false;
void testPrint(string s) {
	if (!isTesting) return;
	cout << endl << s << endl;
}

#define MAX 50
int N, M;
int r, c, d;
bool isWall[MAX][MAX];
bool isClean[MAX][MAX] = { 0, };

string getCurrentStatus() {
	stringstream ss;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			string ch = "o";
			if (isWall[i][j]) ch = "x";
			else if (isClean[i][j]) ch = "v";
			if (i == r && j == c) {
				switch (d) {
				case 0:
					ch += "↑";
					break;
				case 1:
					ch += "→";
					break;
				case 2:
					ch += "↓";
					break;
				case 3:
					ch += "←";
					break;
				}
			}
			else ch += " ";
			ss << ch << ' ';
		}
		ss << endl;
	}
	return ss.str();
}

// 0 북, 1 동, 2 남, 3 서
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

void move(int &r, int &c, int d) {
	r += di[d];
	c += dj[d];
}

int getBackwards(int d) {
	return (d + 2) % 4;
}

void moveBack(int& r, int& c, int d) {
	move(r, c, getBackwards(d));
}

int getCounterClockwise90(int d) {
	return (d - 1 + 4) % 4;
}

void turnCounterClockwise90(int& d) {
	d = getCounterClockwise90(d);
}

bool isInRange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}

bool isGoAble(int r, int c) {
	return isInRange(r, c) && !isWall[r][c];
}

bool canGoBack(int r, int c, int d) {
	int newR = r + di[getBackwards(d)];
	int newC = c + dj[getBackwards(d)];
	return isGoAble(newR, newC);
}

bool isAllAroundClean(int r, int c) {
	for (int k = 0; k < 4; k++) {
		int newR = r + di[k];
		int newC = c + dj[k];
		if (!isGoAble(newR, newC)) continue;
		if (!isClean[newR][newC]) return false;
	}
	return true;
}

int main(void) {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> isWall[i][j];
		}
	}
	int cleanCnt = 0;
	while (true) {
		testPrint(getCurrentStatus());
		if (!isClean[r][c]) {
			isClean[r][c] = true;
			cleanCnt++;
			testPrint("cleaned " + to_string(r) + ", " + to_string(c));
		}
		if (isAllAroundClean(r, c)) {
			if(canGoBack(r, c, d)) {
				moveBack(r, c, d);
				testPrint("moved back");
				continue;
			}
			testPrint("all clean, quit");
			break;
		}
		turnCounterClockwise90(d);
		testPrint("turned left");
		if (isGoAble(r + di[d], c + dj[d])
			&& !isClean[r + di[d]][c + dj[d]]) {
			move(r, c, d);
			testPrint("moved");
		}
	}
	testPrint(getCurrentStatus());
	cout << cleanCnt;
}