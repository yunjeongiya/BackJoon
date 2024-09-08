#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define endl '\n'
#define MAX 100
int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> Q;
vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void visit(pair<int, int> v) {
    for (int i = 0; i < 4; i++) {
        int a = v.first + d[i].first;
        int b = v.second + d[i].second;
        if (a >= 0 && a < N && b >= 0 && b < M
            && map[a][b] && !visited[a][b]) // 이동 가능
        {
            Q.push(pair<int, int>(a, b));
            map[a][b] = map[v.first][v.second] + 1;
            visited[a][b] = true;
        }
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        cout << endl;
        for (int j = 0; j < M; j++) {
            cout << map[i][j];
        }
    }
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    Q.push(pair<int, int>(0, 0));
    visited[0][0] = true;
    while (!Q.empty()) {
        pair<int, int> v = Q.front();
        Q.pop();
        visit(v);
        //print();
    }

    if(map[N - 1][M - 1]) cout << map[N - 1][M - 1];
}