#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void sol() {
    char c;
    int ducks[2500] = { 0, };
    map<char, int> m = { {'q',1}, {'u',2}, {'a',3}, {'c',4}, {'k',5} };
    int cnt = 0;
    while (cin >> c) {
        bool found = false;
        for (int i = 0; i < 2500; i++) {
            ducks[i] %= m.size();
            if (m[c] - 1 == ducks[i]) {
                ducks[i]++;
                found = true;
                cnt = max(cnt, i + 1);
                break;
            }
        }
        if (!found) {
            cout << -1;
            return;
        }
    }
    for (int i = 0; i < 2500; i++) {
        ducks[i] %= m.size();
        if (ducks[i] != 0) {
            cout << -1;
            return;
        }
    }
    cout << cnt;

}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}