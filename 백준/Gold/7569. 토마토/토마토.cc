#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'
#define MAX 100

int N, M, H;
int box[MAX][MAX][MAX]; // 익은 토마토 1, 안 익은 0, 비어 있는 -1
struct Tomato {
    int x, y, z, day;
};
queue<Tomato> Q; // x, y, z, day 저장
int unripe_tomato_cnt = 0;
int day_passed = 0;

void ripen(Tomato tomato) {

    int directions[6][3] = { {1, 0, 0}, {0, 1, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
    for (int* direction : directions) {
        int nextX = tomato.x + direction[0];
        int nextY = tomato.y + direction[1];
        int nextZ = tomato.z + direction[2];

        int today = tomato.day + 1;

        if (nextX < 0 || nextY < 0 || nextZ < 0 ||
            nextX >= H || nextY >= N || nextZ >= M||
            box[nextX][nextY][nextZ] == -1) {
            continue;
        }
        if (box[nextX][nextY][nextZ] == 0) {
            box[nextX][nextY][nextZ] = 1;
            unripe_tomato_cnt--;
            Q.push({ nextX, nextY, nextZ, today });
            day_passed = max(day_passed, today); // 토마토 익혔을 때만 시간 흐름
        }
    }
}

int32_t main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    Q.push({ i, j, k, 0 });
                }
                else if (box[i][j][k] == 0) {
                    unripe_tomato_cnt++;
                }
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
