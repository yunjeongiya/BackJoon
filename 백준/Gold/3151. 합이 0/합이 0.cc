#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define NMAX 10000
int N, A[NMAX];

long long sol() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);
    long long cnt = 0; // cnt <= NC3 <= 10000C3
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            int need = -(A[i] + A[j]);
            cnt += upper_bound(A + j + 1, A + N, need)
                    - lower_bound(A + j + 1, A + N, need);
        }
    }
    return cnt;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << sol();
}