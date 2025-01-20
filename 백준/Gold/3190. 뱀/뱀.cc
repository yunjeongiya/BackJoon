#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define SNAKE_RIGHT 0
#define SNAKE_DOWN 1
#define SNAKE_LEFT 2
#define SNAKE_UP 3
#define EMPTY 4
#define APPLE 5

void print(vector<vector<int>>& board) {
	for (auto& row : board) {
		for (auto& cell : row) {
			char c;
			switch (cell) {
			case SNAKE_RIGHT:
			case SNAKE_LEFT:
				c = '-';
				break;
			case SNAKE_UP:
			case SNAKE_DOWN:
				c = '|';
				break;
			case EMPTY:
				c = 'X';
				break;
			case APPLE:
				c = 'O';
				break;
			}
			cout << c << ' ';
		}
		cout << endl;
	}
	cout << "----------------------" << endl;
}

int main(void) {
	int N, K;
	cin >> N >> K;
	vector<vector<int>> board(N, vector<int>(N, EMPTY));
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[--x][--y] = APPLE; //TS 사과 위치 입력 잘못받음
	}
	int L;
	cin >> L;

	//오른쪽부터 시계방향 순
	const int dx[] = { 0, 1, 0, -1 };
	const int dy[] = { 1, 0, -1, 0 };

	int sec = 0, headX = 0, headY = 0, tailX = 0, tailY = 0;
	board[headX][headY] = SNAKE_RIGHT;
	int i = 0;
	while (true) {

		int X = -1;
		char C;
		if (i < L) {
			cin >> X >> C;
			i++;
		}

		// X초 될 때까지 or 주어진 방향 변환 끝난 이후엔 죽을 때까지 전진
		int direction = board[headX][headY];
		while (sec < X || X == -1) {
			sec++;
			headX += dx[direction];
			headY += dy[direction];
			if (headX < 0 || headX >= N || headY < 0 || headY >= N
				|| (board[headX][headY] != EMPTY && board[headX][headY] != APPLE)) {
				cout << sec;
				return 0;
			}
			if (board[headX][headY] != APPLE) {
				int tailDirection = board[tailX][tailY]; //TS 아래랑 순서 바꿔서 잘못함.
				board[tailX][tailY] = EMPTY;
				tailX += dx[tailDirection];
				tailY += dy[tailDirection];
			}
			board[headX][headY] = direction;

			//cout << "sec: " << sec << endl;
			//print(board);
		}

		//방향 바꾸기
		if (C == 'L') direction--;
		else direction++;
		(direction += 4) %= 4;
		board[headX][headY] = direction;
		//cout << "turned " << C << ", after " << X << "sec" << endl;
		//print(board);

	}
}