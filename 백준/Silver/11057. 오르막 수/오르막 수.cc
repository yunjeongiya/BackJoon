#include <iostream>
#define DIV 10007
using namespace std;

void dp(int* cnt) {
    for (int i = 8; i >= 0; i--) {
        cnt[i] %= DIV;
        cnt[i] += cnt[i+1];
    }
}

void sol() {
    int N;
    cin >> N;
    int cnt[10];
    fill_n(cnt, 10, 1);

    while(N--) dp(cnt);

    cout << cnt[0] % DIV;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}