#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    //TS0 MAX size 배열로 했는데 왜 stack overflow??
    vector<vector<char>> map(N + 1, vector<char>(M + 1));
    vector<vector<int>> dist(N + 1, vector<int>(M + 1, -1));
    vector<vector<int>> distWithBreak(N + 1, vector<int>(M + 1, -1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }    
    //상하좌우순
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    queue<pair<int, int>> Q;
    Q.push(make_pair(1, 1));
    dist[1][1] = 1;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        //cout << endl << "from: " << x << ", " << y;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX < 1 || nextY < 1 || nextX > N || nextY > M) continue;
            //cout << endl << "check: " << nextX << ", " << nextY;

            if (map[nextX][nextY] == '1') { //TS3: char로 받았더니 '0'도 true
                if (dist[x][y] == -1) continue;
                int newDistWithBreak = dist[x][y] + 1;
                if (newDistWithBreak < distWithBreak[nextX][nextY] || distWithBreak[nextX][nextY] == -1) {
                    distWithBreak[nextX][nextY] = newDistWithBreak;
                }
                else continue; //TS4: else continue 들 안해줬더니 무한루프
            }
            else {
                if (dist[x][y] != -1) {
                    int newDist = dist[x][y] + 1;
                    if (newDist < dist[nextX][nextY] || dist[nextX][nextY] == -1) {
                        dist[nextX][nextY] = newDist;
                    }
                    else continue;
                }
                else if (distWithBreak[x][y] != -1) {
                    int newDistWithBreak = distWithBreak[x][y] + 1;
                    if (newDistWithBreak < distWithBreak[nextX][nextY] || distWithBreak[nextX][nextY] == -1) {
                        distWithBreak[nextX][nextY] = newDistWithBreak;
                    }
                    else continue;
                }
                else continue;
            }
            Q.push(make_pair(nextX, nextY));

            //cout << "------------" << endl;
            //for (int i = 1; i <= N; i++) {
            //    for (int j = 1; j <= M; j++) {
            //        cout << "(" << dist[i][j] << ", " << distWithBreak[i][j] << ")";
            //    }
            //    cout << endl;
            //}
        }
    }
    if (dist[N][M] == -1) {
        if (distWithBreak[N][M] == -1) {
            cout << -1;
        }
        else {
            cout << distWithBreak[N][M];
        }
    }
    else {
        if (distWithBreak[N][M] == -1) {
            cout << dist[N][M];
        }
        else {
            cout << min(dist[N][M], distWithBreak[N][M]);
        }
    }
}
