#include <iostream>
using namespace std;
#define endl '\n'
#define LMAX 200000
#define NMAX 100000 // min(L-1, 100000)

// 거리, 충전소 수, 최대 방문 횟수, 충전소 위치[]
int L, N, K, A[LMAX];

bool check(int capacity) {
    int current = capacity;
    int location = 0;
    int seen = 0;
    int chargeCnt = 0;
    while (current > 0 && location < L) {
        location++;
        current--;
        if (location == A[seen] && chargeCnt < K) { // 충전 가능한 상황
            int nextTarget = A[++seen] ? A[seen] : L;
            if ( current < nextTarget - location) { // 충전 필요 확인 후 충전
                chargeCnt++;
                current = capacity;
            }
        }
    }
    return !(current == 0 && location < L);
}

int sol() {
    cin >> L >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 5 <= L(목표 이동 거리) 이라 capacity = 0 일 때 무조건 False
    // 완충 상태로 출발하므로 capacity = L 일 때 무조건 True
    int l = 0, h = L;

    while (l + 1 < h) {
        int m = (l + h) / 2;
        if (check(l) == check(m)) {
            l = m;
        }
        if (check(h) == check(m)) {
            h = m;
        }
    }
    return h;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << sol();
}