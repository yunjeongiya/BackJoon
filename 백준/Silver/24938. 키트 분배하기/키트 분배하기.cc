#include <iostream>
#include <cstdlib> //abs for int
using namespace std;
#define endl '\n'
#define NMAX 200000

void sol() {
    int N, A[NMAX], sum = 0, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    int avg = sum / N;

    for (int i = 0; i < N; i++) {
        A[i] -= avg;
        A[i + 1] += A[i];
        ans += abs(A[i]);
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