#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'
#define MAX 1000

int N, M;
int box[MAX][MAX]; // 익은 토마토 1, 안 익은 0, 비어 있는 -1
struct Tomato {
    int x, y, day;
};
queue<Tomato> Q; // x, y, day 저장
int unripe_tomato_cnt = 0;
int day_passed = 0;

void ripen(Tomato tomato) {
    int x = tomato.x;
    int y = tomato.y;
    int day = tomato.day;

    int directions[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    for (int* direction : directions) {
        int nextX = x + direction[0];
        int nextY = y + direction[1];

        int today = day + 1;

        if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M || box[nextX][nextY] == -1) {
            continue;
        }
        if (box[nextX][nextY] == 0) {
            box[nextX][nextY] = 1;
            unripe_tomato_cnt--;
            Q.push({ nextX, nextY, today });
            day_passed = max(day_passed, today); // 토마토 익혔을 때만 시간 흐름
        }
    }
}

int32_t main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                Q.push({ i, j, 0 });
            }
            else if (box[i][j] == 0) {
                unripe_tomato_cnt++;
            }
        }
    }

    while (!Q.empty()) {
        Tomato tomato = Q.front();
        Q.pop();
        ripen(tomato);
    }

    if (unripe_tomato_cnt) {
        cout << -1;
    }
    else {
        cout << day_passed;
    }

    return 0;
}
