#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define endl '\n'
#define NMAX 100000
void sol() {
    pair<int, int> dots[NMAX];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dots[i].first >> dots[i].second;
    }
    sort(dots, dots + N);

    for (int i = 0; i < N; i++) {
        cout << dots[i].first << ' ' << dots[i].second << endl;
    }
}
int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}