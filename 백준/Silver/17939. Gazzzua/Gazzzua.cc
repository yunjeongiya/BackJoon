#include <iostream>
using namespace std;
#define NMAX 100000
void sol() {
    int N, profit=0, costs[NMAX], max_cost = 0;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> costs[i];
    for (int i = N - 1; i >= 0; i--) {
        if (costs[i] > max_cost) max_cost = costs[i];
        profit += max_cost - costs[i];
    }
    cout << profit;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}