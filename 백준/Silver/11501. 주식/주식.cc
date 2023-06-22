#include <iostream>
#include <vector>
using namespace std;
void sol() {
    int T;
    cin >> T;
    while (T--) {
        int N, max = 0;
        long long profit = 0;
        cin >> N;
        vector<int> costs(N);
        for (int i = 0; i < N; i++) {
            cin >> costs[i];
        }

        for (int i = N - 1; i>=0; i--) {
            if (costs[i] > max) max = costs[i];
            profit += max - costs[i];
        }
        cout << profit << '\n';
    }
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}