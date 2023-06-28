#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define endl '\n'
#define NMAX 10
#define LENMAX 100
int cnt_flip(string str) {
    int cnt = 0;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] != str[i - 1]) cnt++;
    }
    return cnt;
}

void sol() {
    int N, ans = 0, additional_flip = NMAX;
    cin >> N;
    string packs[NMAX];
    for (int i = 0; i < N; i++) {
        cin >> packs[i];
        ans += cnt_flip(packs[i]);
    }
    //O(n!) but n<=10이므로 최대 10! = 3628800
    sort(packs, packs + N);
    do {
        int cnt = 0;
        for (int i = 0; i < N - 1; i++) {
            if (packs[i].back() != packs[i + 1][0]) cnt++;
        }
        additional_flip = min(additional_flip, cnt);
    } while (next_permutation(packs, packs + N));
    cout << ans+additional_flip;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}