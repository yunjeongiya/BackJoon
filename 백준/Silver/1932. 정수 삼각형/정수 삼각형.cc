#include <iostream>
#include <algorithm>
using namespace std;

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int map[501][501];

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> map[i][j];
        }
    }

    while (--n) {
        for (int j = 1; j <= n; j++) {
            map[n][j] += max(map[n + 1][j], map[n + 1][j + 1]);
        }
    }

    cout << map[1][1];
}