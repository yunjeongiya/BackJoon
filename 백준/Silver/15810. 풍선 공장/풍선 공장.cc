#include <iostream>
using namespace std;
#define endl '\n'
#define AMAX 1000000
#define MMAX 1000000
#define NMAX 1000000
int N, M, A[NMAX];
void sol() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    long long l = 1, h = 1LL * (MMAX)*AMAX;
    while (l + 1 < h) {
        long long m = (l + h) / 2, cnt = 0;
        for (int i = 0; i < N; i++) cnt += m / A[i];
        if (cnt < M) l = m;
        else h = m;
    }
    cout << h;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}