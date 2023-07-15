#include <iostream>
#include <cstdlib> //abs for int
#include <queue>
using namespace std;
#define endl '\n'
#define NMAX 200000
int N, A[NMAX], sum = 0, ans = 0;
queue<int> riches, poors;

int share(int rich, int poor) {
    int diff = A[rich] + A[poor];
    int amount;
    if (diff >= 0) {
        amount = A[poor];
        A[rich] = diff;
        A[poor] = 0;
        poors.pop();
    }
    else {
        amount = A[rich];
        A[rich] = 0;
        A[poor] = diff;
        riches.pop();
    }
    return abs(amount * (rich - poor));
}

void sol() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    int avg = sum / N;

    for (int i = 0; i < N; i++) {
        A[i] -= avg;
        while (A[i] > 0) {
            riches.push(i);
            if (poors.empty()) break;
            ans += share(i, poors.front());
        }
        while (A[i] < 0) {
            poors.push(i);
            if (riches.empty()) break;
            ans += share(riches.front(), i);
        }
    }

    cout << ans;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}