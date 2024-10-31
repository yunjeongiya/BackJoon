#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define endl '\n'

vector<vector<char>> grid;
vector<vector<char>> visited;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void bfs(int i, int j, int N) {
    queue<pair<int, int>> Q;
    char color = grid[i][j];
    Q.push(make_pair(i, j));
    visited[i][j] = grid[i][j]; // TS1 빼먹음
    while (!Q.empty()) {
        pair<int, int> node = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int new_i = node.first + dx[k]; //TS2 여기에 i, j 씀...
            int new_j = node.second + dy[k];
            if (0 <= new_i && new_i < N &&
                0 <= new_j && new_j < N &&
                !visited[new_i][new_j] &&
                grid[new_i][new_j] == color)
            {
                Q.push(make_pair(new_i, new_j));
                visited[new_i][new_j] = grid[new_i][new_j];
            }
        }
    }
}

void bfs2(int i, int j, int N) { //R, G 구분 x
    queue<pair<int, int>> Q;
    char color = grid[i][j];
    Q.push(make_pair(i, j));
    while (!Q.empty()) {
        pair<int, int> node = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int new_i = node.first + dx[k];
            int new_j = node.second + dy[k];
            if (0 > new_i || new_i >= N ||
                0 > new_j || new_j >= N ||
                visited[new_i][new_j] ||
                (grid[new_i][new_j] != 'R' &&
                grid[new_i][new_j] != 'G')) continue;
            Q.push(make_pair(new_i, new_j));
            visited[new_i][new_j] = true;
        }
    }
}

int main(void) {
    int N;
    cin >> N;
    grid = vector<vector<char>>(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    //정상인
    visited = vector<vector<char>>(N, vector<char>(N, 0));
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            bfs(i, j, N);
            cnt++;
        }
    }
    cout << cnt << ' ';
    //적록색약 (R, G 구분 x)
    cnt = 0;
    visited = vector<vector<char>>(N, vector<char>(N, 0));
    //visited = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            if (grid[i][j] == 'B') bfs(i, j, N);
            else bfs2(i, j, N);
            cnt++;
        }
    }
    cout << cnt;
}