#include <iostream>
#define MAX 15
using namespace std;
int N, cnt = 0;
bool board[MAX][MAX] = { false };
bool cols[MAX] = { false };
//TS7 TS6으로 충분한 줄 알았는데 여전히 오래걸려서 순회 안하고 체크하도록 변경
bool canPutAt2(int x, int y) {
    if (cols[y]) return false;
    int dx[4] = { 1, 1, -1, -1 };
    int dy[4] = { 1, -1, 1, -1 }; //TS5 같은 줄은 넣을 때 피해 넣고 대각선만 순회해서 시간 절약
    for (int i = 0; i < 4; i++) {
        int xCopy = x;
        int yCopy = y;
        while (true) {
            x += dx[i];
            y += dy[i];
            if (x < 0 || x >= N || y < 0 || y >= N) break;
            if (board[x][y]) return false;
        }
        x = xCopy;
        y = yCopy;
    }
    return true;
}
bool canPutAt(int x, int y) {
    int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
    int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 }; //TS6 TS5를 다 반영하고 나니 오히려 같은 세로줄은 직전만 체크해서 다시 추가. 2개 추가니까 이중for보단 이게 나음.
    //int dx[4] = { 1, 1, -1, -1 };
    //int dy[4] = { 1, -1, 1, -1 }; //TS5 같은 줄은 넣을 때 피해 넣고 대각선만 순회해서 시간 절약
    for (int i = 0; i < 8; i++) {
        int xCopy = x;
        int yCopy = y;
        while (true) {
            x += dx[i];
            y += dy[i];
            if (x < 0 || x >= N || y < 0 || y >= N) break;
            if (board[x][y]) return false;
        }
        x = xCopy;
        y = yCopy;
    }
    return true;
}
void printBoard() {
    cout << "-------------------\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) cout << "[x]";
            else cout << "[ ]";
        }
        cout << "\n";
    }
}

void func(int fixedCnt, int x, int y) {
    if (fixedCnt == N) {
        cnt++;
        //printBoard();
        return;
    }
    //TS5 결국 N개를 놔야 하기 때문에 모든 줄에 하나씩은 있어야 함.
    // -> 이중for문 x 그냥 행마다 하나씩 놓기
    //for (int i = x + 1; i < N; i++) { //TS2 매 번 0부터 탐색하니 동일 답안 여러 개 나옴
    //
    //}
    int i = x + 1;
    for (int j = 0; j < N; j++) {
        //TS7에서 어차피 처리하니 삭제
        //if (j == y) continue; //TS5 같은 줄이면 어차피 놓을 수 없으니 skip해야 시간 절약
        if (!canPutAt2(i, j)) continue; //TS1 board에 이미 놓았는지 체크 안함 -> TS5 반영하면서 필요 없어져서 다시 삭제
        board[i][j] = true;
        cols[j] = true;
        //printBoard();
        func(fixedCnt + 1, i, j);
        board[i][j] = false; //TS0 되돌려놓기 까먹음
        cols[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int j = 0; j < N; j++) {
        board[0][j] = true;
        cols[j] = true;
        func(1, 0, j);
        board[0][j] = false; //TS4 되돌려놓기 또 까먹음
        cols[j] = false;
    }
    cout << cnt;
}
